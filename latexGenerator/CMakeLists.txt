set(HEADER_LIST "${SUDOKUGENERATOR_SOURCE_DIR}/include/latexGenerator/latexGenerator.hpp" "${SUDOKUGENERATOR_SOURCE_DIR}/include/sudoku/sudoku.hpp" "${SUDOKUGENERATOR_SOURCE_DIR}/include/grid/grid.hpp")
set(FILES_LIST "latexGenerator.cpp")

add_library(latexGenerator_library ${FILES_LIST} ${HEADER_LIST})

target_include_directories(latexGenerator_library PRIVATE ../include)
target_compile_features(latexGenerator_library PUBLIC cxx_std_11)