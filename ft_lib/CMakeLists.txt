# Boost options.
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_DEBUG_LIBS OFF)
set(Boost_USE_RELEASE_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.72.0 REQUIRED COMPONENTS filesystem program_options)

set(FT_LIB_SRC src/color.cpp src/log.cpp src/match.cpp src/parser.cpp
               src/print.cpp src/walker.cpp)

add_library(ft_lib ${FT_LIB_SRC})

ft_generate_header(NAME src/version.hpp.in LINK_TARGETS ft_lib)

target_include_directories(ft_lib PUBLIC include)

target_link_libraries(ft_lib ${Boost_LIBRARIES})

set_target_properties(ft_lib PROPERTIES OUTPUT_NAME ft)

target_compile_options(
  ft_lib
  PRIVATE -Wall
          -Wextra
          -Werror
          -Wconversion
          -Wold-style-cast
          -Wlogical-op
          -Wredundant-decls
          -Wshadow
          -Wcast-qual
          -Wformat=2
          -Wswitch-default
          -Wmissing-include-dirs
          -Wctor-dtor-privacy
          -Wdisabled-optimization
          -Weffc++
          -Wmissing-declarations
          -Wuseless-cast
          -Wduplicated-cond
          -Wduplicated-branches
          -pedantic-errors
          -Wsign-conversion
          -Wswitch-enum)

if(ENABLE_PROFILING)
  target_compile_options(ft_lib PRIVATE -pg)
  target_link_options(ft_lib PRIVATE -pg)
endif()
