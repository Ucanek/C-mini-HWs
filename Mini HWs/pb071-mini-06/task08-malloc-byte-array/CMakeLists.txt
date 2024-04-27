cmake_minimum_required(VERSION 3.0)

set(SOURCE_FILES ../libs/pb071_alloc.c)

get_filename_component(NAME ${CMAKE_CURRENT_LIST_DIR} NAME)
project(${NAME})

foreach(MODE IN ITEMS source solution)
    set(SOURCE "${CMAKE_CURRENT_LIST_DIR}/${MODE}.c")

    if (EXISTS ${SOURCE})
        add_executable("${NAME}-${MODE}" ${SOURCE} ${SOURCE_FILES})
    else()
        message(WARNING "${MODE}.c missing in ${NAME}")
    endif()
endforeach()
