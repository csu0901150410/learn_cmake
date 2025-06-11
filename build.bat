::生成build目录
cmake -G "MinGW Makefiles" -B build .

::make ./build/Makefile
cmake --build build