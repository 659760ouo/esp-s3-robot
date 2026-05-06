# Minimum CMake version required by ESP-IDF
cmake_minimum_required(VERSION 3.16)

# Load ESP-IDF's core build rules
include($ENV{IDF_PATH}/tools/cmake/project.cmake)

# Set your project name (matches your folder name)
project(ESP-S3-ROBOT)