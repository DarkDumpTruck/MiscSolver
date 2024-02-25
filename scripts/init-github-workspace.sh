#!/bin/bash

cmake_version="3.28.3"

sudo apt-get update
sudo apt-get upgrade -y
sudo apt-get install gcc-10 g++-10 -y
sudo apt-get remove cmake -y
wget -O cmake.sh https://github.com/Kitware/CMake/releases/download/v$cmake_version/cmake-$cmake_version-linux-x86_64.sh
sudo mkdir /opt/cmake
sudo mkdir /opt/cmake
sudo chmod +x cmake.sh
sudo ./cmake.sh --skip-license --prefix=/opt/cmake
rm -f ./cmake.sh
export PATH=$PATH:/opt/cmake/bin

python3 -m pip install --upgrade pip
pip3 install meson
sudo apt-get install ninja-build -y

meson setup -Dcpp_args="-ffast-math -march=native" build --buildtype=release