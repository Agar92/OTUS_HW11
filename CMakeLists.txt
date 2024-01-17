cmake_minimum_required(VERSION 3.8)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})
project(mapreduce VERSION ${PROJECT_VERSION})
configure_file(include/version.h.in version.h)

project(mapreduce VERSION ${PROJECT_VERSION} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(Threads)
include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories(${CMAKE_BINARY_DIR})

add_executable(mapreduce src/main.cpp)
target_link_libraries(mapreduce
        ${CMAKE_THREAD_LIBS_INIT})

configure_file(test/project_path.h.in project_path.h)
find_package(GTest REQUIRED)
add_executable(test_mapreduce test/test_mapreduce.cpp)
target_link_libraries(test_mapreduce
        ${GTEST_LIBRARIES}
        ${CMAKE_THREAD_LIBS_INIT})


install(TARGETS mapreduce RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT agar10@yandex.ru)
include(CPack)

enable_testing()
add_test(test test_mapreduce)
