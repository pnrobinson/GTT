# Google test test (GTT)
GTestTest

This repository provides a simple example of how to use CMake to compile a C++ project that makes use of both google test and SeqAn.

## What are the files



```
$ mkdir -p build/release
$ cd build/release
$ cmake ../..
```

The CMake script will cause cmake to download (via git clone) the googletest code into the 'release' subdirectory. It will also generate a number of files in the 'release' subdirectory, including the Makefile. Now enter

```
$ make
```
