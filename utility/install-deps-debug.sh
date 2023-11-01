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

curl -OL https://github.com/mongodb/mongo-cxx-driver/releases/download/r3.8.1/mongo-cxx-driver-r3.8.1.tar.gz
tar -xzf mongo-cxx-driver-r3.8.1.tar.gz
cd mongo-cxx-driver-r3.8.1/build

cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr/local
cmake --build .
make install -j 6

cd ../../

##

MODULE_NAME="oatpp-mongo"

git clone --depth 1 --branch 1.3.0 https://github.com/oatpp/$MODULE_NAME
cd $MODULE_NAME
mkdir build
cd build

cmake .. -DOATPP_BUILD_TESTS=OFF
make install -j 6

cd ../../

##########################################################

cd ../
rm -rf tmp
