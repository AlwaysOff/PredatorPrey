cmake_minimum_required(VERSION 3.20)
project(PredatorPrey)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(PredatorPrey Aphid.cpp Aphid.h Bug.cpp Bug.h Grid.cpp Grid.h LadyBug.cpp LadyBug.h PredatorPrey.cpp)

include_directories(c:/SFML/include)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(PredatorPrey ${SFML_LIBRARIES})
endif()



if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()
