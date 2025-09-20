FROM ubuntu:20.04

RUN apt update && \
    apt install -y build-essential clang && \
    rm -rf /var/lib/apt/lists/*


COPY . /app

WORKDIR /app

RUN ls -la

RUN g++ -std=c++17 -o myapp unique_ptr.cpp