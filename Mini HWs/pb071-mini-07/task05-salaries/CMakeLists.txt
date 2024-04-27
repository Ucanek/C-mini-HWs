cmake_minimum_required(VERSION 3.0)

get_filename_component(NAME ${CMAKE_CURRENT_LIST_DIR} NAME)
set(CMAKE_C_FLAGS -std=c99)
project(${NAME})

foreach(MODE IN ITEMS source solution)
    set(SOURCE "${CMAKE_CURRENT_LIST_DIR}/${MODE}.c")

    if (EXISTS ${SOURCE})
        add_executable("${NAME}-${MODE}" ${SOURCE})
    else()
        message(WARNING "${MODE}.c missing in ${NAME}")
    endif()
endforeach()
