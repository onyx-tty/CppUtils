FROM ubuntu:latest AS builder

RUN set -ex;                                                                  \
    apt-get update;                                                           \
    apt-get install -y cmake ninja-build g++ clang qt6-base-dev libgtest-dev

COPY . /app
WORKDIR /app

RUN set -ex;                                      \
    cmake --preset Debug -DCPPUTILS_ENABLE_QT=ON; \
    cmake --build build/Debug

RUN ctest --test-dir /app/build/Debug

