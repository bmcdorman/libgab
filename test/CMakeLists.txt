add_executable(simple ${CMAKE_CURRENT_SOURCE_DIR}/simple.cpp)
target_link_libraries(simple gab)
add_executable(worker ${CMAKE_CURRENT_SOURCE_DIR}/worker.cpp)
target_link_libraries(worker gab)