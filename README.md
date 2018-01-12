# SeqAn GTest CMake Framework

This repository provides a simple example of how to use CMake to compile a C++ project that makes use of both google test and SeqAn. On my Kubuntu system, the package installation of seqan fails to install a ```seqan-config.cmake``` file in a system path that is automatically searched by the cmake system. For this reason, I have written a CMake file that clones both seqan and gtest to the build directory. Probably this can be simplified with subsequent releases.

## Install SeqAn
Using the CMake files provided, there is no need to install SeqAn separately. However, consult these pages as needed on your system.
[SeqAn](http://www.seqan.de/) is an extremely powerful C++ template library for the analysis of biological sequences. There is an extensive [documentation](http://seqan.readthedocs.io/en/master/index.html#) for getting started. Please consult [this page}(http://seqan.readthedocs.io/en/master/Infrastructure/Use/Install.html#infra-use-install) for information on how to install SeqAn on your system. Currently, the recommended way is to install from GitHub.
```
$ git clone https://github.com/seqan/seqan.git
```




## Building
To build the projects, we will create a new directory called build. We need to tell CMake the paths to Seqan as follows (note the name of the application is fase).

```
$ mkdir build
$ cd build
$ cmake ..
$ make
./fase
```

To create unit tests, enter the following commands

```
$ mkdir build
$ cd build
$ cmake -Dtest=ON ..
$ make
./runUnitTests
```

The first time it is run, the CMake script will cause cmake to download (via git clone) the googletest code and the SeqAn code into the 'build' subdirectory. It will also generate a number of files in the 'build' subdirectory, including the Makefile.
