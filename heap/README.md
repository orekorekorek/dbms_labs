# Requirements

First of all you need to install [Docker Desktop](https://www.docker.com/products/docker-desktop/) to your computer

# Setup

```console
$ git clone
$ cd dbms_labs/heap
$ make build
```

# Running

```console
$ make run # run executable main
$ make run_tests
```

# Running without Docker

## Requirements

```
git
g++
make
cmake
```

## Setup
1. Delete original `Makefile` for docker usage and rename `Makefile.example -> Makefile`
2. Build executable and tests
```bash
$ make build_executable
$ make build_tests
```

## Running
```bash
$ make run_executable
$ make run_tests
```
