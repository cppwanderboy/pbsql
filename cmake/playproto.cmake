find_package(Protobuf CONFIG REQUIRED)
find_package(SQLite3 REQUIRED)

set(PROTO_BINARY_DIR "${CMAKE_SOURCE_DIR}/include/proto_def")

add_library(proto-objects OBJECT "${CMAKE_SOURCE_DIR}/proto/position.proto"
        "${CMAKE_SOURCE_DIR}/proto/index.proto")
target_link_libraries(proto-objects PUBLIC protobuf::libprotobuf)
target_include_directories(proto-objects PUBLIC "$<BUILD_INTERFACE:${PROTO_BINARY_DIR}>")


protobuf_generate(
        TARGET proto-objects
        IMPORT_DIRS "${CMAKE_SOURCE_DIR}/proto"
        PROTOC_OUT_DIR "${PROTO_BINARY_DIR}")