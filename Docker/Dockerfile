FROM ubuntu:16.04

RUN apt update && \
    apt install -y build-essential clang && \
    rm -rf /var/lib/apt/lists/*

COPY . /app

WORKDIR /app

RUN ls -la

