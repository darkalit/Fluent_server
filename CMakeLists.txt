cmake_minimum_required(VERSION 3.8)
project("FluentServer" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(${PROJECT_NAME}-lib
  src/dto/StatusDto.hpp

  src/controller/PingController.hpp

  src/AppComponent.hpp
  src/SwaggerComponent.hpp
)

find_package(oatpp 1.3.0 REQUIRED)
find_package(oatpp-swagger 1.3.0 REQUIRED)
find_package(oatpp-websocket 1.3.0 REQUIRED)

target_link_libraries(
  ${PROJECT_NAME}-lib
  PUBLIC oatpp::oatpp
  PUBLIC oatpp::oatpp-swagger
  PUBLIC oatpp::oatpp-websocket
)

add_definitions(
  -DOATPP_SWAGGER_RES_PATH="${oatpp-swagger_INCLUDE_DIRS}/../bin/oatpp-swagger/res"
)

target_include_directories(${PROJECT_NAME}-lib PUBLIC src)

add_executable(${PROJECT_NAME}-exe
  src/App.cpp
)
target_link_libraries(${PROJECT_NAME}-exe ${PROJECT_NAME}-lib)
add_dependencies(${PROJECT_NAME}-exe ${PROJECT_NAME}-lib)

set_target_properties(${PROJECT_NAME}-lib ${PROJECT_NAME}-exe
  PROPERTIES
    CXX_STANDARD 17
    CXX_EXTENSIONS OFF
    CXX_STANDARD_REQUIRED ON
    LINKER_LANGUAGE CXX
)

