# Optoma ESP32 Remote

This project allows you to send commands to an Optoma ZH403 projector over RS-232 via a Wi-Fi REST server using an ESP32 microcontroller. The ESP32 connects to a Wi-Fi network and hosts a RESTful API, enabling remote control of the projector through HTTP requests.

## Features
- Send power on/off commands to the Optoma ZH403 projector.
- Communicate with the projector using RS-232 protocol.
- Control the projector remotely via a Wi-Fi REST server.

## Hardware Setup

### Components
- ESP32
- MAX3232 TTL to RS-232 Adapter

### Connections
- ESP32 Pin 16 (TX2) -> MAX3232 TX
- ESP32 Pin 17 (RX2) -> MAX3232 RX
- ESP32 5V -> MAX3232 VCC
- ESP32 GND -> MAX3232 GND

```
    +-------------------+       +------------------+            +------------------+
    |      ESP32        |       |     MAX3232      |            |   Optoma ZH403   |
    |                   |       |                  |            |                  |
    |    5V  ---------> |-------| VCC              |  straight  |                  |
    |    GND ---------> |-------| GND              |------------|                  |
    |    TX2 (16) ----> |-------| TX               |   RS232    |                  |
    |    RX2 (17) ----> |-------| RX               |            |                  |
    +-------------------+       +------------------+            +------------------+
```

## Setup
1. Connect the ESP32 to the Optoma ZH403 projector using an RS-232 interface. Ensure you use a straight-through cable, not a crossed (null modem) cable.
2. Upload the code to the ESP32.
3. Configure the Wi-Fi credentials by connecting to the 'Optoma ZH403 - ESP Remote' access point and provide your Wi-Fi credentials.
4. Access the REST server to send commands to the projector.

## Usage
- Power On: Send a GET request to `/?command=ON`.
- Power Off: Send a GET request to `/?command=OFF`.

## Example
```sh
curl http://<esp32-ip-address>/poweron
curl http://<esp32-ip-address>/poweroff
```
