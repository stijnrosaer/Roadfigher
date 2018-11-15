set(SRC main.cpp)

add_executable(roadfighter ${SRC})

install(TARGETS roadfighter DESTINATION ${PROJECT_SOURCE_DIR}/bin)