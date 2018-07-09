cmake_minimum_required(VERSION 3.2)

set(PATCH_VERSION "0")
if($ENV{TRAVIS_BUILD_NUMBER})
  set(PATCH_VERSION $ENV{TRAVIS_BUILD_NUMBER})
endif()

if( NOT CMAKE_BUILD_TYPE )
  set( CMAKE_BUILD_TYPE MinSizeRel CACHE STRING
       "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel."
       FORCE )
endif()

project(helloworld VERSION 0.6.${PATCH_VERSION})

find_package (Threads)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

configure_file("${PROJECT_SOURCE_DIR}/version.h.in" "${PROJECT_BINARY_DIR}/version.h")

add_executable(helloworld_cli main.cpp)
target_include_directories(helloworld_cli PRIVATE "${PROJECT_SOURCE_DIR}")
target_include_directories(helloworld_cli PRIVATE "${PROJECT_BINARY_DIR}")
target_include_directories(helloworld_cli PRIVATE "${PROJECT_SOURCE_DIR}/spdlog/include")
target_include_directories(helloworld_cli PRIVATE "${PROJECT_SOURCE_DIR}/rapidjson/include")


if(${CMAKE_BUILD_TYPE} EQUAL "Debug")
    target_compile_definitions(helloworld_cli PRIVATE SPDLOG_TRACE_ON)
endif()


add_library(helloworld lib.cpp)
target_include_directories(helloworld PRIVATE "${PROJECT_BINARY_DIR}")
target_include_directories(helloworld PRIVATE "${PROJECT_SOURCE_DIR}/spdlog/include")

add_executable(test_main_cli test_main.cpp)
target_include_directories(test_main_cli PRIVATE "${PROJECT_BINARY_DIR}")
target_include_directories(test_main_cli PRIVATE ${Boost_INCLUDE_DIR})
target_include_directories(test_main_cli PRIVATE "${PROJECT_SOURCE_DIR}/spdlog/include")

set_target_properties(helloworld_cli test_main_cli PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

set_target_properties(test_main_cli PROPERTIES
  COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
)

target_link_libraries(helloworld_cli 
	helloworld
	${CMAKE_THREAD_LIBS_INIT}
)

target_link_libraries(test_main_cli
  ${Boost_LIBRARIES}
  helloworld
)

install(TARGETS helloworld_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT kolobrod2002@yandex.ru)

include (CPack)

enable_testing()

add_test(test_version_valid test_main_cli)

configure_file("${PROJECT_SOURCE_DIR}/bintray.json.in" "${PROJECT_BINARY_DIR}/bintray.json")

message("CPACK_PACKAGE_VERSION: ${CPACK_PACKAGE_VERSION}")
message("CPACK_PACKAGE_FILE_NAME: ${CPACK_PACKAGE_FILE_NAME}")
message("CPACK_PACKAGE_NAME: ${CPACK_PACKAGE_NAME}")

