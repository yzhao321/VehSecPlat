# VehSecPlat

Copyright 2023, UCSC, ZJU, SCUT.

All rights reserved.

author: Yinyuan Zhao (yzhao321 [at] ucsc [dot] edu)

## How to Use
### How to Use Bin
- Set up compiler for selected board
- Compile
  - cd build
  - chmod +x ./*.sh
  - ./build.sh
- Run
  - ./run.sh

### How to Use Client of Platform
- Command Adding
  - ./src/app/client/src/client_cmd.c
  - Add method to g_vehClientCmdList
- Command Calling
  - ./run.sh
  - tap the cmd name defined in g_vehClientCmdList

### How to Add Board Support to Platform
- to ./bsp
- Create the board folder
- add public define, driver, and CMakeLists

## Description
### Introduction of Vehicle Security
- ECU
  - Interactions between vhicle modules can be abstracted
- Security Model
  - Layer
    - V2X
    - ECU
    - Chip
  - Interface
    - OBD
    - CAN
    - Autonomous Driving
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