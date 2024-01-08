cmake_minimum_required(VERSION 3.0)
project(my_raylib_game CXX)
#set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

# Adding Raylib
include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # don't build the supplied example games

FetchContent_Declare(
    raylib
    GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
    GIT_TAG "master"
    GIT_PROGRESS TRUE
)

FetchContent_MakeAvailable(raylib)



# Manually listing source files
set(PROJECT_SOURCES
    sources/main.cpp
    "sources/global_stuff.h"
    sources/drawing.h
    sources/drawing.cpp
    sources/speicher.h 
    sources/speicher.cpp
    sources/reactions.cpp
    sources/reactions.h
    sources/button.h 
    sources/button.cpp
    
    # Add more files here, if necessary
)

# Declaring our executable
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

# Include directories
set(PROJECT_INCLUDE "${CMAKE_CURRENT_LIST_DIR}/include")  # Adjust the path accordingly
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_INCLUDE})

# Linking libraries
target_link_libraries(${PROJECT_NAME} PRIVATE raylib
   # winmm
   glfw
)
# Setze den Pfad zu den DLL-Dateien
set(MYSQL_LIB_DIR "${CMAKE_CURRENT_LIST_DIR}/database/lib64")

# Füge das Verzeichnis mit den DLLs zum Ausführungsverzeichnis hinzu (optional, abhängig von deinen Anforderungen)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin")

# Verlinke die DLLs mit dem ausführbaren Ziel
target_link_libraries(${PROJECT_NAME} PRIVATE
    #${MYSQL_LIB_DIR}/libcrypto-3-x64.dll
    #${MYSQL_LIB_DIR}/libssl-3-x64.dll
    #${MYSQL_LIB_DIR}/mysqlcppconn-9-vs14.dll
    ${MYSQL_LIB_DIR}/mysqlcppconn8-2-vs14.dll
    # Füge hier weitere DLLs hinzu, wenn vorhanden
)

# Setting ASSETS_PATH
target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/") # Set the asset path macro to the absolute path on the dev machine
#target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="./assets") # Set the asset path macro in release mode to a relative path that assumes the assets folder is in the same directory as the game executable