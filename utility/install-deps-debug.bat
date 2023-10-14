rd /s /q tmp

MD tmp
cd tmp\

:: ##########################################################
:: install oatpp

set MODULE_NAME="oatpp"

git clone --depth 1 --branch 1.3.0 https://github.com/oatpp/%MODULE_NAME%

cd %MODULE_NAME%\
MD build
cd build\

cmake ..
cmake --build . --target INSTALL

cd ..\..\

:: ##########################################################
:: install oatpp-swagger

set MODULE_NAME="oatpp-swagger"

git clone --depth 1 --branch 1.3.0 https://github.com/oatpp/%MODULE_NAME%

cd %MODULE_NAME%\
MD build
cd build\

cmake ..
cmake --build . --target INSTALL

cd ..\..\

:: ##########################################################
:: install oatpp-websocket

set MODULE_NAME="oatpp-websocket"

git clone --depth 1 --branch 1.3.0 https://github.com/oatpp/%MODULE_NAME%

cd %MODULE_NAME%\
MD build
cd build\

cmake ..
cmake --build . --target INSTALL

cd ..\..\
:: ##########################################################

cd ..\
rd /s /q tmp
