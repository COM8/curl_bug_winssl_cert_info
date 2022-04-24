cmake_minimum_required(VERSION 3.20)
project(curl_bug_winssl_cert_info)

set(CMAKE_CXX_STANDARD 11)

add_executable(curl_bug_winssl_cert_info main.cpp)

if(WIN32) # Install dlls in the same directory as the executable on Windows
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
endif()

include(FetchContent)
# Curl configuration
message(STATUS "Configuring build in curl...")

# We only need HTTP (and HTTPS) support:
set(HTTP_ONLY ON)
set(BUILD_CURL_EXE OFF)
set(BUILD_TESTING OFF)

set(SSL_ENABLED ON)
set(CURL_USE_SCHANNEL ON)

FetchContent_Declare(curl
                     URL                    https://github.com/curl/curl/releases/download/curl-7_82_0/curl-7.82.0.tar.xz
                     URL_HASH               SHA256=0aaa12d7bd04b0966254f2703ce80dd5c38dbbd76af0297d3d690cdce58a583c) # the file hash for curl-7.82.0.tar.xz
FetchContent_MakeAvailable(curl)

# Group under the "external" project folder in IDEs such as Visual Studio.
if(BUILD_CURL_EXE)
    set_property(TARGET curl PROPERTY FOLDER "external")
endif()        
set_property(TARGET libcurl PROPERTY FOLDER "external")

target_link_libraries(curl_bug_winssl_cert_info PRIVATE CURL::libcurl)
