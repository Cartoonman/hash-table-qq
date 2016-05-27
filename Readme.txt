This assignment was coded in C++ 11.


Windows and Linux binaries have been supplied. I believe the Windows binary is compiled by MinGW64. Linux binary was complined with gcc in Linux.


Source code can be compiled by any gcc compiler that supports C++11. No non-std libraries are required.

Compile the main.cpp file to get the program. 
e.g. g++ main.cpp 

If you recieve errors, you may not have C++11 compiling enabled or supported. Try:
g++ main.cpp -std=c++0x
g++ main.cpp -std=c++11

The command I used on Windows with MinGW64:
g++ main.cpp g++ main.cpp -static-libgcc -static-libstdc++