
add_executable(day01_part01)

file(GLOB_RECURSE DAY01_PART01_SOURCES "*.cpp")
file(GLOB_RECURSE DAY01_PART01_HEADERS "*.h")

target_sources(day01_part01 PRIVATE ${DAY01_PART01_SOURCES} ${DAY01_PART01_HEADERS})

target_include_directories(day01_part01 PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../data
)

add_custom_target(copier_fichier_01
    ALL
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/input.txt
    ${CMAKE_CURRENT_BINARY_DIR}/input.txt
    DEPENDS day01_part01
)
