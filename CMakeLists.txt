cmake_minimum_required(VERSION 3.20)

project(ToDoList LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# add_compile_options(-Wall -Wextra)

set(FLTK_ROOT "C:/Program Files (x86)/FLTK/bin")
find_package(FLTK REQUIRED)

set(TARGET "ToDoList")

add_executable(
    ${TARGET}
    src/Graph_lib/Graph.cpp
    src/Graph_lib/GUI.cpp
    src/Graph_lib/Window.cpp
    src/main/MainWindow.cpp
    src/main/MainWindow.h
    src/main/year.h
    src/main/year.cpp
    src/main/month.h
    src/main/month.cpp
    src/another_part/ChangeTaskInfo.cpp
    src/another_part/DayDraw.cpp
    src/another_part/DayLogic.cpp
    src/another_part/TaskWindow.cpp
    src/another_part/MyButton.h
    src/another_part/ChangeTaskInfo.h
    src/another_part/DayDraw.h
    src/another_part/DayLogic.h
    src/another_part/PARAMETERS.h
    src/another_part/TaskWindow.h
    src/new_another_part/chrono.h
    src/new_another_part/chrono.cpp
    src/new_another_part/task_manager2.cpp
    src/new_another_part/task_manager.h
    src/main/main.cpp
)

target_include_directories(${TARGET} PRIVATE 
    ${CMAKE_SOURCE_DIR}/src
    ${FLTK_INCLUDE_DIR}
)

target_link_directories(${TARGET} PRIVATE
    ${FLTK_INCLUDE_DIR}/../lib
)

target_link_libraries(${TARGET} PRIVATE 
    ${FLTK_LIBRARIES}
    fltk_jpeg
    fltk_png
    fltk_z
)
