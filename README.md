# PlaneTracker

A Raspberry Pi-based ADS-B telemetry server written in C++.

## Features

### System Telemetry

- CPU temperature monitoring
- Memory usage tracking
- CPU usage tracking
- Timestamped logging (monitor.CSV)

### ADS-B

- WIP

## Hardware

- Raspberry Pi 4 Model B (8GB)
- FlightAware Pro Stick Plus
- 1090 MHz ADS-B antenna (3dBi)

## Software

- Pi24 OS / DietPi
- C++20
- g++

## Building

### SCP to the Raspberry Pi:
```bash
scp .\*.cpp .\*.h pi@192.168.1.XXX:~/PlaneTracker/
```

### Compile on the Raspberry Pi:

```bash
g++ -std=c++20 *.cpp -o PlaneTracker
```

## Running

### SSH session

```bash
./PlaneTracker
```

### Recommended

```bash
tmux
./PlaneTracker
```
Detach
```
Ctrl + B, then D
```
Reattach
```
tmux attach
```

## Data output

Logs are saved in:
```
monitor.csv
```

Format:
```
timestamp,temperature,memory_mb,cpu_load
2026-06-21 23:00:00,48.2,243,0.09
```

## Current Status

### v0.1

- [x] Basic Pi Telemetry
- [ ] 
- [ ] 
- [ ] Aircraft count

## Roadmap

### Phase 1
- Raspberry Pi telemetry

### Phase 2


### Phase 3


### Phase 4


### Phase 5
