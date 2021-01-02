add_executable(ft_bin main.cpp)

target_link_libraries(ft_bin ft_lib)

set_target_properties(ft_bin PROPERTIES OUTPUT_NAME ft)

if(ENABLE_PROFILING)
  target_compile_options(ft_bin PRIVATE -pg)
  target_link_options(ft_bin PRIVATE -pg)
endif()
