set(HEADER_LIST "${SUDOKUGENERATOR_SOURCE_DIR}/include/grid/grid.hpp")
set(FILES_LIST "grid.cpp")

add_library(grid_library ${FILES_LIST} ${HEADER_LIST})

target_include_directories(grid_library PRIVATE ../include)
target_compile_features(grid_library PUBLIC cxx_std_11)