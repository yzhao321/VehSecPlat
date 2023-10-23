# VehSecPlat

Copyright 2023, UCSC, ZJU, SCUT.

All rights reserved.

Author: Yinyuan Zhao (yzhao321 [at] ucsc [dot] edu)

## How to Use
### Compile and Run
- Compile
  - [Option: Set up compiler for selected board]
  - cd build
  - chmod +x ./*.sh
  - ./build.sh
- Run
  - ./run.sh

### Shell Client
- Command Adding
  - ./src/app/client/src/client_cmd.c
  - Add method to g_vehClientCmdList
- Command Calling
  - ./run.sh
  - Tap the cmd name defined in g_vehClientCmdList

### Board Support
- ./bsp
- Create the board folder
- Add public define, driver, and CMakeLists

## Description
### Introduction of Vehicle Security
- ECU
  - Interactions between vehicle modules can be abstracted
- Security Model
  - Layer
    - V2X
    - ECU
    - Chip
  - Interface
    - OBD
    - CAN
    - Autonomous Driving
    - ...
  - Method
    - Security Principles
      - Confidentiality
      - Availability
      - Integrity
    - Measures
      - Denial of Service
      - Tampering with Data
      - Information Disclose
      - Spoofing Identity
      - ...


### Motivation of Vehicle Security Platform
- Usability
  - Auto attacks and board controlling support
- Maintainability
  - Avoid code rewriting caused by changing attack interfaces or board hardware
  - Adding new att/def methods can reuse platform code


### Architecture of Vehicle Security Platform
- Driver Level
  - Uniform application methods
  - Encapsulation for different hardward interfaces of different boards/chips
- Application Level
  - Implementation of attack and defense logic