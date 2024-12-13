
add_executable(day04)


file(GLOB_RECURSE DAY04_SOURCES "*.cpp")
file(GLOB_RECURSE DAY04_HEADERS "*.h")

target_sources(day04 PRIVATE ${DAY04_SOURCES} ${DAY04_HEADERS})

target_include_directories(day04 PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/.
)


add_custom_target(copier_fichier_04
    ALL
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/input.txt
    ${CMAKE_CURRENT_BINARY_DIR}/input.txt
    DEPENDS day04
)
