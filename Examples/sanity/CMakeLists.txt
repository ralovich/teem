project (TeemSampleProject)

cmake_minimum_required(VERSION 2.8)

if(COMMAND cmake_policy)
  cmake_policy(SET CMP0003 NEW)
endif()

find_package(Teem REQUIRED)
include(${Teem_USE_FILE})

add_executable(sample sanity.c)
target_link_libraries(sample ${Teem_LIBRARIES})
