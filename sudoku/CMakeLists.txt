set(HEADER_LIST "${SUDOKUGENERATOR_SOURCE_DIR}/include/sudoku/sudoku.hpp" "${SUDOKUGENERATOR_SOURCE_DIR}/include/grid/grid.hpp")
set(FILES_LIST "sudoku.cpp")

add_library(sudoku_library ${FILES_LIST} ${HEADER_LIST})

target_include_directories(sudoku_library PRIVATE ../include)

target_compile_features(sudoku_library PUBLIC cxx_std_11)