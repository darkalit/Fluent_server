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

git clone https://github.com/mongodb/mongo-c-driver.git

cd mongo-c-driver\
git checkout 1.24.4
python build\calc_release_version.py > VERSION_CURRENT

MD cmake-build
cd cmake-build\

cmake .. -DCMAKE_INSTALL_PREFIX=C:\mongo-c-driver -DCMAKE_PREFIX_PATH=C:\mongo-c-driver
cmake --build . --target INSTALL

cd ..\..\

:: ##

git clone --depth 1 --branch r3.8.1 https://github.com/mongodb/mongo-cxx-driver.git
cd mongo-cxx-driver
cd build

cmake .. -DCMAKE_CXX_STANDARD=17 -DCMAKE_INSTALL_PREFIX=C:\mongo-cxx-driver -DBSONCXX_POLY_USE_BOOST=0 -DCMAKE_PREFIX_PATH=C:\mongo-c-driver
cmake --build . --target INSTALL

cd ..\..\

:: ##

git clone --depth 1 --branch 1.3.0 https://github.com/oatpp/oatpp-mongo.git

cd oatpp-mongo\
MD build
cd build\

cmake .. -DCMAKE_PREFIX_PATH=C:\mongo-cxx-driver -DOATPP_BUILD_TESTS=OFF
cmake -- build . --target INSTALL

cd ..\..\

:: ##########################################################

cd ..\
rd /s /q tmp
