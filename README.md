# PlaneTracker

A Raspberry Pi-based ADS-B telemetry server written in C++.

## Features

- Monitor Raspberry Pi CPU temperature

## Hardware

- Raspberry Pi 4 Model B 8GB
- FlightAware Pro Stick Plus
- 3dBi ADS-B 1090 MHz magnetic antenna

## Software

- Pi24 OS
- C++20
- g++

## Building

SCP to the Raspberry Pi:
```bash
scp .\*.cpp .\*.h pi@192.168.1.XXX:~/PlaneTracker/
```

Compile on the Raspberry Pi:

```bash
g++ -std=c++20 *.cpp -o PlaneTracker
```

Run:

```bash
./PlaneTracker
```

## Current Status

### v0.1

- [x] Read Pi temperature
- [ ] CPU usage
- [ ] Memory usage
- [ ] Aircraft count

## Roadmap

### Phase 1
- Raspberry Pi telemetry

### Phase 2


### Phase 3


### Phase 4


### Phase 5
