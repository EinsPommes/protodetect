# ProtoDetect für Flipper Zero

ProtoDetect ist eine fortschrittliche Anwendung für das Flipper Zero, die sich auf die automatische Erkennung und Analyse von Funk- und IR-Protokollen spezialisiert.

## 🌟 Hauptfunktionen

- **Automatische Protokoll-Erkennung**: Unterstützt Sub-GHz, IR und RFID-Signale
- **Signalanalyse**: Erkennt Pulsbreite, Frequenz und Modulationsart
- **Visualisierung**: Grafische Darstellung von Signalen und Datenstrukturen
- **Signal-Replay**: Aufzeichnung und Wiedergabe von Signalen
- **Datenexport**: Speicherung als CSV/JSON für weitere Analysen

## 📥 Installation

1. Laden Sie die neueste `.fap`-Datei aus dem [Releases](https://github.com/einspommes/protodetect/releases)-Bereich herunter
2. Kopieren Sie die `.fap`-Datei in das Verzeichnis `apps/Tools` auf Ihrem Flipper Zero
3. Starten Sie die App über das "Apps"-Menü auf Ihrem Flipper Zero

## 🛠️ Entwicklung

### Voraussetzungen

- [Flipper Zero Build Environment](https://github.com/flipperdevices/flipperzero-firmware)
- GCC ARM Toolchain
- Git

### Build-Anweisungen

```bash
# Klonen Sie das Repository
git clone https://github.com/einspommes/protodetect.git

# Wechseln Sie in das Projektverzeichnis
cd protodetect

# Kompilieren Sie die Anwendung
./fbt fap_protodetect
```

## 📝 Lizenz

Dieses Projekt ist unter der MIT-Lizenz lizenziert - siehe die [LICENSE](LICENSE)-Datei für Details.

## ⚠️ Haftungsausschluss

Diese Software ist nur für Bildungs- und Forschungszwecke gedacht. Die Verwendung dieser Software zur Manipulation oder zum unbefugten Zugriff auf Systeme ist illegal und wird nicht unterstützt. 