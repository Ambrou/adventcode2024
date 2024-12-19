
add_executable(day05)

target_compile_features(day05 PRIVATE cxx_std_23)

file(GLOB_RECURSE DAY05_SOURCES "*.cpp")
file(GLOB_RECURSE DAY05_HEADERS "*.h")

target_sources(day05 PRIVATE ${DAY05_SOURCES} ${DAY05_HEADERS})

target_include_directories(day05 PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/.
)


add_custom_target(copier_fichier_05
    ALL
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/input.txt
    ${CMAKE_CURRENT_BINARY_DIR}/input.txt
    DEPENDS day05
)
