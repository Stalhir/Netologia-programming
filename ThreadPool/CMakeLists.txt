cmake_minimum_required(VERSION 4.0)
project(untitled1)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled1 main.cpp
        thread_pool/threadpool.cpp
        thread_pool/threadpool.h
        thread_pool/safe_queue/SafeQueue.tpp
        thread_pool/safe_queue/SafeQueue.h)
