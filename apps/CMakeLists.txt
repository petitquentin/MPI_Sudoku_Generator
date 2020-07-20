file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/output/readMe.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/output)

add_executable(testGenerateSudoku testGenerateSudoku.cpp)
target_compile_features(testGenerateSudoku PRIVATE cxx_std_17)

target_link_libraries(testGenerateSudoku PRIVATE sudoku_library grid_library stdc++fs)
target_include_directories(testGenerateSudoku PUBLIC ${PROJECT_SOURCE_DIR}/include)
install(TARGETS testGenerateSudoku DESTINATION bin)

add_executable(testGetScore testGetScore.cpp)
target_compile_features(testGetScore PRIVATE cxx_std_17)

target_link_libraries(testGetScore PRIVATE sudoku_library grid_library stdc++fs)
target_include_directories(testGetScore PUBLIC ${PROJECT_SOURCE_DIR}/include)
install(TARGETS testGetScore DESTINATION bin)

add_executable(testSortVector testSortVector.cpp)
target_compile_features(testSortVector PRIVATE cxx_std_17)

target_link_libraries(testSortVector PRIVATE sudoku_library grid_library stdc++fs)
target_include_directories(testSortVector PUBLIC ${PROJECT_SOURCE_DIR}/include)
install(TARGETS testSortVector DESTINATION bin)

add_executable(testMPISendReceive testMPISendReceive.cpp)
target_compile_features(testMPISendReceive PRIVATE cxx_std_17)

target_link_libraries(testMPISendReceive PRIVATE sudoku_library grid_library stdc++fs)
target_include_directories(testMPISendReceive PUBLIC ${PROJECT_SOURCE_DIR}/include)
install(TARGETS testMPISendReceive DESTINATION bin)

add_executable(testLatexGenerator testLatexGenerator.cpp)
target_compile_features(testLatexGenerator PRIVATE cxx_std_17)

target_link_libraries(testLatexGenerator PRIVATE latexGenerator_library sudoku_library grid_library stdc++fs)
target_include_directories(testLatexGenerator PUBLIC ${PROJECT_SOURCE_DIR}/include)
install(TARGETS testLatexGenerator DESTINATION bin)