
add_executable(day03)
target_compile_features(day03 PRIVATE cxx_std_23)

file(GLOB_RECURSE DAY02_SOURCES "*.cpp")
file(GLOB_RECURSE DAY02_HEADERS "*.h")

target_sources(day03 PRIVATE ${DAY02_SOURCES} ${DAY02_HEADERS})

target_include_directories(day03 PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/.
)


add_custom_target(copier_fichier_03
    ALL
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/input.txt
    ${CMAKE_CURRENT_BINARY_DIR}/input.txt
    DEPENDS day03
)
