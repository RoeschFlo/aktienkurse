cmake_minimum_required(VERSION 3.28.1)

project(our_lord_and_saviour)

include_directories(include)

set(SQL_API_PATH ${CMAKE_CURRENT_LIST_DIR}/external/mysql_connector_c)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_LIST_DIR}/out)

add_executable(${PROJECT_NAME} 
                    src/main.cpp
                    src/gui.cpp
                    src/button.cpp 
                    src/textbox.cpp)


#exe wird mit mysql gelinkt
target_link_libraries(${PROJECT_NAME} ${SQL_API_PATH}/lib/libmysql.lib)



#exe wird mit raylib gelinkt
target_link_libraries(${PROJECT_NAME}
    ${CMAKE_CURRENT_LIST_DIR}/external/raylib/lib/libraylib.a
    
)

target_link_libraries(${PROJECT_NAME}     winmm
)