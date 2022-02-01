CMAKE_MINIMUM_REQUIRED(VERSION 3.21)
PROJECT(LeetCodeDaily)

SET(CMAKE_CXX_STANDARD 23)

# -Ofast -march=native -mtune=native -finline-functions -ffast-math -fomit-frame-pointer
SET(CMAKE_CXX_FLAGS "-Wall")

ADD_EXECUTABLE(LeetCodeDaily main.cpp)

# ADD_SUBDIRECTORY(2112)
ADD_SUBDIRECTORY(2201)
ADD_SUBDIRECTORY(2202)
ADD_SUBDIRECTORY(more)
