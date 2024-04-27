cmake_minimum_required(VERSION 3.0)

get_filename_component(NAME ${CMAKE_CURRENT_LIST_DIR} NAME)
project(${NAME})

if (NOT EXISTS "${CMAKE_BINARY_DIR}/test_dir")
    file(COPY test_dir DESTINATION ${CMAKE_BINARY_DIR})
endif()

foreach(MODE IN ITEMS source solution)
    set(SOURCE "${CMAKE_CURRENT_LIST_DIR}/${MODE}.c")

    if (EXISTS ${SOURCE})
    add_executable("${NAME}-${MODE}" ${SOURCE})
    else()
        message(WARNING "${MODE}.c missing in ${NAME}")
    endif()
endforeach()
