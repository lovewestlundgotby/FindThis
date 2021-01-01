# Boost options.
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_DEBUG_LIBS OFF)
set(Boost_USE_RELEASE_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.72.0 REQUIRED COMPONENTS filesystem program_options)

set(FIND_THIS_SRC
    main.cpp
    color.cpp
    log.cpp
    match.cpp
    parser.cpp
    printer.cpp
    walker.cpp)

add_executable(ft ${FIND_THIS_SRC})

ft_generate_header(NAME version.hpp.in LINK_TARGETS ft)

target_link_libraries(ft ${Boost_LIBRARIES})

target_compile_options(
  ft
  PRIVATE -Wall
          -Wcast-qual
          -Wconversion
          -Wctor-dtor-privacy
          -Wdisabled-optimization
          -Wduplicated-branches
          -Wduplicated-cond
          -Weffc++
          -Werror
          -Werror
          -Wextra
          -Wformat=2
          -Wlogical-op
          -Wmissing-declarations
          -Wmissing-include-dirs
          -Wold-style-cast
          -Wredundant-decls
          -Wshadow
          -Wsign-conversion
          -Wswitch-default
          -Wswitch-enum
          -Wuseless-cast
          -pedantic-errors)

if(ENABLE_PROFILING)
  target_compile_options(ft PRIVATE -pg)
  target_link_options(ft PRIVATE -pg)
endif()
