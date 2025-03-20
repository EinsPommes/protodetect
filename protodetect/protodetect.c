#include <furi.h>
#include <gui/gui.h>
#include <input/input.h>
#include <stdlib.h>
#include <storage/storage.h>
#include <notification/notification.h>
#include <notification/notification_messages.h>
#include "protodetect_icons.h"

typedef struct {
    Gui* gui;
    ViewPort* view_port;
    FuriMessageQueue* event_queue;
    NotificationApp* notifications;
    
    // Zustandsvariablen
    bool is_running;
    uint8_t current_menu;
    // Weitere Variablen für die Signalanalyse werden hier hinzugefügt
} ProtoDetect;

typedef enum {
    EventTypeTick,
    EventTypeKey,
} EventType;

typedef struct {
    EventType type;
    InputEvent input;
} ProtoDetectEvent;

static void draw_callback(Canvas* canvas, void* ctx) {
    ProtoDetect* app = ctx;
    canvas_clear(canvas);
    canvas_set_font(canvas, FontPrimary);
    
    // Hauptmenü zeichnen
    canvas_draw_str(canvas, 2, 10, "ProtoDetect v1.0");
    canvas_draw_line(canvas, 0, 13, 128, 13);
    
    // Menüpunkte
    canvas_set_font(canvas, FontSecondary);
    canvas_draw_str(canvas, 2, 25, "1. Signal Scan");
    canvas_draw_str(canvas, 2, 35, "2. Gespeicherte Signale");
    canvas_draw_str(canvas, 2, 45, "3. Einstellungen");
}

static void input_callback(InputEvent* input_event, void* ctx) {
    ProtoDetect* app = ctx;
    furi_message_queue_put(app->event_queue, input_event, FuriWaitForever);
}

ProtoDetect* protodetect_alloc() {
    ProtoDetect* app = malloc(sizeof(ProtoDetect));
    
    app->gui = furi_record_open(RECORD_GUI);
    app->view_port = view_port_alloc();
    app->event_queue = furi_message_queue_alloc(8, sizeof(ProtoDetectEvent));
    app->notifications = furi_record_open(RECORD_NOTIFICATION);
    
    view_port_draw_callback_set(app->view_port, draw_callback, app);
    view_port_input_callback_set(app->view_port, input_callback, app);
    gui_add_view_port(app->gui, app->view_port, GuiLayerFullscreen);
    
    app->is_running = true;
    app->current_menu = 0;
    
    return app;
}

void protodetect_free(ProtoDetect* app) {
    view_port_enabled_set(app->view_port, false);
    gui_remove_view_port(app->gui, app->view_port);
    view_port_free(app->view_port);
    furi_message_queue_free(app->event_queue);
    
    furi_record_close(RECORD_GUI);
    furi_record_close(RECORD_NOTIFICATION);
    
    free(app);
}

int32_t protodetect_app(void* p) {
    UNUSED(p);
    ProtoDetect* app = protodetect_alloc();
    ProtoDetectEvent event;
    
    while(app->is_running) {
        if(furi_message_queue_get(app->event_queue, &event, 100) == FuriStatusOk) {
            if(event.type == EventTypeKey) {
                // Tasteneingaben verarbeiten
                if(event.input.type == InputTypeShort) {
                    if(event.input.key == InputKeyBack) {
                        app->is_running = false;
                    }
                }
            }
        }
        view_port_update(app->view_port);
    }
    
    protodetect_free(app);
    return 0;
} 