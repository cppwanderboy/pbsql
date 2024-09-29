cmake_minimum_required(VERSION 3.29)
project(playground)

set(CMAKE_CXX_STANDARD 20)

include("cmake/playproto.cmake")


include_directories(include)

add_executable(playground
        test/main.cpp)
target_link_libraries(playground PRIVATE protobuf::libprotoc protobuf::libprotobuf protobuf::libprotobuf-lite)
target_link_libraries(playground PRIVATE SQLite::SQLite3)
target_link_libraries(playground PRIVATE proto-objects)


add_executable(sqlite
        test/sqlite.cpp)
target_link_libraries(sqlite PRIVATE protobuf::libprotoc protobuf::libprotobuf protobuf::libprotobuf-lite)
target_link_libraries(sqlite PRIVATE SQLite::SQLite3)
target_link_libraries(sqlite PRIVATE proto-objects)
