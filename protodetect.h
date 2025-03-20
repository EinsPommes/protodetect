#pragma once

#include <furi.h>

#ifdef __cplusplus
extern "C" {
#endif

// Haupteinstiegspunkt der Anwendung
int32_t protodetect_app(void* p);

// Konstanten für die Signalanalyse
#define PROTODETECT_MAX_SAMPLES 1024
#define PROTODETECT_MIN_PULSE_LENGTH 100  // in Mikrosekunden
#define PROTODETECT_MAX_PULSE_LENGTH 10000  // in Mikrosekunden

// Unterstützte Protokolltypen
typedef enum {
    ProtocolTypeSubGhz,
    ProtocolTypeInfrared,
    ProtocolTypeRFID
} ProtocolType;

// Modulationsarten
typedef enum {
    ModulationAM,
    ModulationFM,
    ModulationASK,
    ModulationFSK,
    ModulationOOK
} ModulationType;

// Struktur für erkannte Protokolle
typedef struct {
    ProtocolType type;
    ModulationType modulation;
    uint32_t frequency;
    uint32_t bit_length;
    uint32_t pulse_length;
    char* name;
    char* description;
} DetectedProtocol;

#ifdef __cplusplus
}
#endif 