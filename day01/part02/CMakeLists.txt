
add_executable(day01_part02)

file(GLOB_RECURSE DAY01_PART02_SOURCES "*.cpp")
file(GLOB_RECURSE DAY01_PART02_HEADERS "*.h")

target_sources(day01_part02 PRIVATE ${DAY01_PART02_SOURCES} ${DAY01_PART02_HEADERS})

target_include_directories(day01_part02 PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../data
)
