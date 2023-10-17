# VehSecPlat

A Vehicle Security Platform for Hardware/Software Co-implementation

## Architecture
### Directory Structure
```
│── app
│   │── client            # Client for Shell
│   │── comm              # Communication Stack
│   │── service           # Att/Def Logic
│   └── syst              # System Control
└── bsp                   # Board Support Platform
    │── rp                # Board rp
    └── ...               # Other Board
```

## Get Started
### Compile and Run
- Compile
  - Set up compiler for selected board
  - Build via cmake
  ```
  cd build
  chmod +x ./*.sh
  ./build.sh
  ```
- Run
  ```
  ./run.sh
  ```


## Devlopemnt
### Shell Command
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

