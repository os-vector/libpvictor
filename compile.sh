#!/bin/bash

rm -rf build install
mkdir build install
cd build
cmake \
  -DCMAKE_C_COMPILER="${HOME}/.anki/vicos-sdk/dist/5.3.0-r07/prebuilt/bin/arm-oe-linux-gnueabi-clang" \
  -DCMAKE_CXX_COMPILER="${HOME}/.anki/vicos-sdk/dist/5.3.0-r07/prebuilt/bin/arm-oe-linux-gnueabi-clang++" \
  -DCMAKE_INSTALL_PREFIX=$(pwd)/../install \
  ..
make
make install
