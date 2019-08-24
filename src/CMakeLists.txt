set(FIND_THIS_SRC
  main.cpp
  )

set(Boost_USE_STATIC_LIBS        ON)  # only find static libs
set(Boost_USE_DEBUG_LIBS         OFF) # ignore debug libs and
set(Boost_USE_RELEASE_LIBS       ON)  # only find release libs
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
find_package(Boost 1.36.0 REQUIRED COMPONENTS program_options)

add_executable(ft
               ${FIND_THIS_SRC})

target_link_libraries(ft
                      ${Boost_LIBRARIES}
                      )
