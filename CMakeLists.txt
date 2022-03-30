cmake_minimum_required(VERSION 2.8)

project(CCV)

set(CCV_src main.cpp functions.cpp class_1.cpp class_0.cpp class.cpp)
set(CCV_hdr operators.h functions.h class_1.h class_0.h class.h AT.h)

add_executable(${PROJECT_NAME} ${CCV_src} ${CCV_hdr})