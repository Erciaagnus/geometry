cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_VERBOSE_MAKEFILE ON)

project(
    PRINTING_HELLO_WORLD
    LANGUAGES CXX
    VERSION 1.0.0
    DESCRIPTION "C++ Project Template"
    HOMEPAGE_URL "https://github.com/Inah-choi/cpp_project_template.git"
)
message(STATUS)
message(STATUS "Started all process in ${PROJECT_NAME} CMakeLists.txt.")
message(STATUS)

set(CPP_COMPILE_FLAGS_WINDOWS /W4 /WX /permissive-)
set(CPP_COMPILE_FLAGS_LINUX -Wall -Wpedantic -Wextra -Werror)

if(NOT CPP_COMPILE_FLAGS)
    if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
        set(CPP_COMPILE_FLAGS ${CPP_COMPILE_FLAGS_WINDOWS})
    else()
        set(CPP_COMPILE_FLAGS ${CPP_COMPILE_FLAGS_LINUX})
    endif()
endif()

# 프로젝트 루트 경로를 설정합니다. CMakeLists.txt 파일이 위치한 디렉토리의 경로를 저장합니다.
set(${PROJECT_NAME}_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
# 소스 코드 디렉토리 경로를 설정합니다.
set(${PROJECT_NAME}_SOURCE_PATH "${${PROJECT_NAME}_ROOT_PATH}/src")
# 헤더 파일이 있는 디렉토리 경로를 설정합니다.
set(${PROJECT_NAME}_INCLUDE_PATH "${${PROJECT_NAME}_ROOT_PATH}/include")
# 서드파티 라이브러리 등 !외부!에서 가져온 코드가 있는 디렉토리 경로를 설정합니다.
set(${PROJECT_NAME}_THIRDPARTY_PATH "${${PROJECT_NAME}_ROOT_PATH}/thirdparty")
# 내가 내부에서 만든 소프트웨어 관리하는 모듈 관리 폴더
set(${PROJECT_NAME}_MODULE_PATH "${${PROJECT_NAME}_ROOT_PATH}/module")
# 테스트 코드가 있는 디렉토리 경로를 설정합니다.
set(${PROJECT_NAME}_TEST_PATH "${${PROJECT_NAME}_ROOT_PATH}/test")
# 어플리케이션 코드가 있는 디렉토리 경로를 설정합니다. excutable (프로젝트의 주 실행파일)
set(${PROJECT_NAME}_APPLICATION_PATH "${${PROJECT_NAME}_ROOT_PATH}/application")
# 리소스 파일의 경로
# resource file : 그래픽 리소스(이미지, 아이콘), 텍스트 파일, 설정 파일, 음원 파일, 또는 어플리케이션에서 사용하는 외부 자원들
set(${PROJECT_NAME}_RESOURCE_PATH "${${PROJECT_NAME}_ROOT_PATH}/resource")

# Message for the project information
message(STATUS "---------------- Project information ----------------")
message(STATUS "PROJECT_NAME: ${PROJECT_NAME}")
message(STATUS "${PROJECT_NAME}_VERSION: ${PROJECT_VERSION}")
message(STATUS "${PROJECT_NAME}_DESCRIPTION: ${PROJECT_DESCRIPTION}")
message(STATUS "${PROJECT_NAME}_HOMEPAGE_URL: ${PROJECT_HOMEPAGE_URL}")
message(STATUS "")

if(NOT PARSED_SYSTEM_INFO)
    # Message for the system information
    message(STATUS "-------------- CMake information --------------")
    message(STATUS "CMake version: ${CMAKE_VERSION}")
    message(STATUS "")
    message(STATUS "-------------- System information --------------")
    message(STATUS "System architecture name: ${CMAKE_SYSTEM_PROCESSOR}")
    message(STATUS "System OS name: ${CMAKE_SYSTEM_NAME}")
    message(STATUS "System OS version: ${CMAKE_SYSTEM_VERSION}")
    message(STATUS "")
    message(STATUS "-------------- Compiler information --------------")
    message(STATUS "C++ compiler id: ${CMAKE_CXX_COMPILER_ID}")
    message(STATUS "C++ compiler version: ${CMAKE_CXX_COMPILER_VERSION}")
    message(STATUS "C++ Compile options: ${CPP_COMPILE_FLAGS}")
    message(STATUS "")
    message(STATUS "------------- C++ standard information -------------")
    message(STATUS "C++ Build type: ${CMAKE_BUILD_TYPE}")
    message(STATUS "C++ standard version: ${CMAKE_CXX_STANDARD}")
    message(STATUS "C++ standard required: ${CMAKE_CXX_STANDARD_REQUIRED}")
    message(STATUS "C++ extensions: ${CMAKE_CXX_EXTENSIONS}")
    message(STATUS "")

    set(PARSED_SYSTEM_INFO TRUE)
endif()


# Message for the project path information
message(STATUS "--------------- Project path information ---------------")
message(STATUS "${PROJECT_NAME}_ROOT_PATH: ${${PROJECT_NAME}_ROOT_PATH}")
message(STATUS "${PROJECT_NAME}_INCLUDE_PATH: ${${PROJECT_NAME}_INCLUDE_PATH}")
message(STATUS "${PROJECT_NAME}_SOURCE_PATH: ${${PROJECT_NAME}_SOURCE_PATH}")
message(STATUS "${PROJECT_NAME}_THIRDPARTY_PATH: ${${PROJECT_NAME}_THIRDPARTY_PATH}")
message(STATUS "${PROJECT_NAME}_MODULE_PATH: ${${PROJECT_NAME}_MODULE_PATH}")
message(STATUS "${PROJECT_NAME}_TEST_PATH: ${${PROJECT_NAME}_TEST_PATH}")
message(STATUS "${PROJECT_NAME}_APPLICATION_PATH: ${${PROJECT_NAME}_APPLICATION_PATH}")
message(STATUS "${PROJECT_NAME}_RESOURCE_PATH: ${${PROJECT_NAME}_RESOURCE_PATH}")
message(STATUS "")

add_subdirectory(${${PROJECT_NAME}_THIRDPARTY_PATH})
add_subdirectory(${${PROJECT_NAME}_MODULE_PATH})
# add_subdirectory(${${PROJECT_NAME}_APPLICATION_PATH})

# base 구조
set(${PROJECT_NAME}_SOURCE_FILES
    src/main.cpp
    #Add source files here
)

# ! If you want to make a library, use the following code
# add_library(${PROJECT_NAME} STATIC
# ${${PROJECT_NAME}_SOURCE_FILES}
# )

# If you want to make an executable, use the following code
add_executable(${PROJECT_NAME}
${${PROJECT_NAME}_SOURCE_FILES}
)

# ! If you want to add include directories and link libraries, use the following code
target_include_directories(${PROJECT_NAME} PUBLIC
${${PROJECT_NAME}_INCLUDE_PATH}
)

#Add include path here
target_link_libraries(${PROJECT_NAME} PRIVATE
    UTILS
)

#Add libraries here
# add_dependencies(${PROJECT_NAME}
# )

#Add dependencies here
target_compile_options(${PROJECT_NAME} PRIVATE
${CPP_COMPILE_FLAGS}
)

message(STATUS)
message(STATUS "Finished all process in ${PROJECT_NAME} CMakeLists.txt.")
message(STATUS)