# Multiplicative Persistence

This is a simple program to calculate the multiplicative persistence of a number.

Inspired by [this video](https://www.youtube.com/watch?v=Wim9WJeDTHQ) by Numberphile.

# Code explanation

The code is pretty simple. It takes a number and multiplies all its digits together. It then repeats this process until the number is a single digit. The number of times this process is repeated is the multiplicative persistence of the number.

Right now the code is using a unsigned long long to store the number to add but this limits the max numbers which can be computed. 

ullong_max = 18'446'744'073'709'551'615

Current record holder for multiplicative persistence is 277'777'788'888'899 with a persistence of 11.

This means if the next number isn't in the ullong_max range, I will have to change the code to use a different data type. Which can go beyond the ullong_max range.

# Need to run the code

## Linux

### Prerequisites

Install the required dependencies:

```bash
sudo apt-get update
sudo apt-get install -y \
    build-essential \
    cmake \
    libgl-dev \
    libglu1-mesa-dev \
    libxrandr-dev \
    libxinerama-dev \
    libxcursor-dev \
    libxi-dev \
    libxxf86vm-dev \
    libglfw3-dev
```

Install ImGui library locally (if not already installed):
- Download and build ImGui from https://github.com/ocornut/imgui
- Install to `/usr/local/lib` and `/usr/local/include`

### Build

```bash
cmake -B cmake-build-debug -S .
cmake --build cmake-build-debug --target MultiplicativePersistence -j$(nproc)
```

### Run

```bash
./cmake-build-debug/MultiplicativePersistence
```

**Note:** On systems using Wayland, if you encounter GTK or libdecor errors, the application automatically forces X11 backend for compatibility.

## Windows

- dear imgui library installed locally
- GLFW library installed locally

# To do

- Add vcpkg support
  - Need to wait for next clion version because vcpkg support is broken in 2020.2.2
- Make it faster
  - Currently, the rate is linked to the update rate of the window
  - Needs to be changed to a separate thread
  - tried it but getting error 3...
- Add code to make save and load work
  - Done but needs an interface to say where to load from and where to save to
- Make the MP_Window a table
  - Done but need to align the text