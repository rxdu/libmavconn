cmake_minimum_required(VERSION 2.8.3)
project(libmavconn)

############
## Config ##
############
include(CheckCXXCompilerFlag)
check_cxx_compiler_flag("-std=c++14" COMPILER_SUPPORTS_STD_CXX14)
if (NOT COMPILER_SUPPORTS_STD_CXX14)
  check_cxx_compiler_flag("-std=c++11" COMPILER_SUPPORTS_STD_CXX11)
endif ()

if (COMPILER_SUPPORTS_STD_CXX14)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
elseif (COMPILER_SUPPORTS_STD_CXX11)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
else ()
  message(FATAL_ERROR "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif ()

## Put all binary files into /bin and libraries into /lib
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

## Find libraries
find_package(console_bridge REQUIRED)
find_package(Boost REQUIRED COMPONENTS system)

###########
## Build ##
###########

include_directories(
  include
  ${Boost_INCLUDE_DIRS}
  ${console_bridge_INCLUDE_DIRS}
)

## Declare a cpp library
add_library(mavconn
  src/mavlink_helpers.cpp
  src/interface.cpp
  src/serial.cpp
  src/udp.cpp
  src/tcp.cpp
)
target_link_libraries(mavconn
  ${Boost_LIBRARIES}
  ${console_bridge_LIBRARIES}
)

#############
## Install ##
#############
# TO BE ADDED
