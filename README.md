# Google test test (GTT)
GTestTest

This repository provides a simple example of how to use CMake to compile a C++ project that makes use of both google test and SeqAn.


## Install SeqAn
[SeqAn](http://www.seqan.de/) is an extremely powerful C++ template library for the analysis of biological sequences. There is an extensive [documentation](http://seqan.readthedocs.io/en/master/index.html#) for getting started. Please consult [this page}(http://seqan.readthedocs.io/en/master/Infrastructure/Use/Install.html#infra-use-install) for information on how to install SeqAn on your system. For instance, to install SeqAN on an Ubuntu system, enter the following command.
```
sudo apt install seqan-dev
```




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

To enable testing, enter
```
$ cmake -Dtest=ON ../..
$ make test
```
