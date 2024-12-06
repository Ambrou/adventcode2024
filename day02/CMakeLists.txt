
add_executable(day02)

file(GLOB_RECURSE DAY02_SOURCES "*.cpp")
file(GLOB_RECURSE DAY02_HEADERS "*.h")

target_sources(day02 PRIVATE ${DAY02_SOURCES} ${DAY02_HEADERS})

target_include_directories(day02 PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/.
)


add_custom_target(copier_fichier_02
    ALL
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/input.txt
    ${CMAKE_CURRENT_BINARY_DIR}/input.txt
    DEPENDS day02
)
