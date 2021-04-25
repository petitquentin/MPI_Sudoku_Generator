set(HEADER_LIST "${SUDOKUGENERATOR_SOURCE_DIR}/include/sudoku/sudoku.pb.h" "${SUDOKUGENERATOR_SOURCE_DIR}/proto/sudoku.pb.h")
set(FILES_LIST "sudoku.pb.cc")

add_library(sudokupb_library ${FILES_LIST} ${HEADER_LIST})

target_link_libraries(sudokupb_library ${PROTOBUF_LIBRARIES})
target_include_directories(sudokupb_library PRIVATE ../include)

target_compile_features(sudokupb_library PUBLIC cxx_std_11)