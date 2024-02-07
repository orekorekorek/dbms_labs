FROM alpine:3.17.0 AS build

WORKDIR /app

RUN apk update && apk add --no-cache git g++ make cmake

COPY . .

# BUILD TESTS

RUN cmake -S . -B build && cmake --build build

# build executable

RUN g++ -std=c++20 -o main.exe main.cpp
