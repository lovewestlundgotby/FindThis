function(ft_generate_header)
  set(options)
  set(oneValueArgs NAME)
  set(multiValueArgs LINK_TARGETS)
  cmake_parse_arguments("" "${options}" "${oneValueArgs}" "${multiValueArgs}"
                        ${ARGN})

  string(REGEX REPLACE "\.in$" "" name ${_NAME})
  string(REPLACE "/" ";" path_list ${name})
  list(LENGTH path_list num_path_elements)
  math(EXPR second_to_last "${num_path_elements} - 1")
  list(INSERT path_list ${second_to_last} "generated")
  list(JOIN path_list "/" generated_path)
  configure_file(${_NAME} ${generated_path})

  string(REPLACE "/" ";" generated_path_list ${generated_path})
  list(POP_BACK generated_path_list)
  list(JOIN generated_path_list "/" generated_dir)
  foreach(target ${_LINK_TARGETS})
    target_include_directories(
      ${target} PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/${generated_dir})
  endforeach()
endfunction()
