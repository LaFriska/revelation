#!/usr/bin/env bash
set -e

ARCH=$(uname -m)
ARCH_FLAG=""

case "$ARCH" in
    x86_64)
        ;;
    arm64|aarch64)
        ARCH_FLAG="-DCMAKE_OSX_ARCHITECTURES=arm64"
        ;;
    *)
        ;;
esac


mkdir -p build
rm -rf build/*
cd build
cmake .. $ARCH_FLAG
make -j"$(nproc 2>/dev/null || sysctl -n hw.ncpu 2>/dev/null || echo 4)"
cd ..

./build/revelation
