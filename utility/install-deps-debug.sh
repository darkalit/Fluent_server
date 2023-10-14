#!/bin/sh

rm -rf tmp

mkdir tmp
cd tmp

##########################################################
## install oatpp

MODULE_NAME="oatpp"

git clone --depth 1 --branch 1.3.0 https://github.com/oatpp/$MODULE_NAME

cd $MODULE_NAME
mkdir build
cd build

cmake ..
make install -j 6

cd ../../

##########################################################
## install oatpp-swagger

MODULE_NAME="oatpp-swagger"

git clone --depth 1 --branch 1.3.0 https://github.com/oatpp/$MODULE_NAME

cd $MODULE_NAME
mkdir build
cd build

cmake ..
make install -j 6

cd ../../

##########################################################
## install oatpp-websocket

MODULE_NAME="oatpp-websocket"

git clone --depth 1 --branch 1.3.0 https://github.com/oatpp/$MODULE_NAME

cd $MODULE_NAME
mkdir build
cd build

cmake ..
make install -j 6

cd ../../
##########################################################

cd ../
rm -rf tmp
