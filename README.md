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

- dear imgui in the same directory as the code
- GLFW in the same directory as the code

# To do

- Add vcpkg support
  - Need to wait for next clion version because vcpkg support is broken in 2020.3.1
- Make it faster
  - Currently the rate is linked to the update rate of the window
  - Needs to be changed to a separate thread