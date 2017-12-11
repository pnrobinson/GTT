# Google test test (GTT)
GTestTest

This repository provides a simple example of how to use CMake to compile a C++ project that makes use of both google test and SeqAn.


## Install SeqAn
[SeqAn](http://www.seqan.de/) is an extremely powerful C++ template library for the analysis of biological sequences. There is an extensive [documentation](http://seqan.readthedocs.io/en/master/index.html#) for getting started. Please consult [this page}(http://seqan.readthedocs.io/en/master/Infrastructure/Use/Install.html#infra-use-install) for information on how to install SeqAn on your system. Currently, the recommended way is to install from GitHub.
```
$ git clone https://github.com/seqan/seqan.git
```

We will need to use the paths to two subdirectories.
  seqan
  ..include
  ..util/cmake

I will refer to the path to the cloned seqn directory as /path/to/seqan, but obviously replace this with the correct values for your system.


## Building
To build the projects, we will create a new directory called build. We need to tell CMake the paths to Seqan as follows (note the name of the application is fase).

```
$ mkdir build
$ cd build
$ cmake -DCMAKE_PREFIX_PATH=/path/to/seqan/util/cmake -DSEQAN_INCLUDE_PATH=~/path/to/seqan/include ..
$ make
./fase
```

To create unit tests, enter the following commands

```
$ mkdir build
$ cd build
$ cmake -DCMAKE_PREFIX_PATH=/path/to/seqan/util/cmake -DSEQAN_INCLUDE_PATH=~/path/to/seqan/include -Dtest=ON ..
$ make
./runUnitTests
```

The first time it is run, the CMake script will cause cmake to download (via git clone) the googletest code into the 'build' subdirectory. It will also generate a number of files in the 'build' subdirectory, including the Makefile.
