FROM alpine:3.17.0 AS build

WORKDIR /app

# TODO specify versions
RUN apk update && apk add --no-cache g++ make

COPY . .

RUN g++ -std=c++20 main.cpp heap.cpp -o main.exe
