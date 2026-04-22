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

add_executable(testEvaluateGrid testEvaluateGrid.cpp)
target_compile_features(testEvaluateGrid PRIVATE cxx_std_17)

target_link_libraries(testEvaluateGrid PRIVATE latexGenerator_library sudoku_library grid_library stdc++fs)
target_include_directories(testEvaluateGrid PUBLIC ${PROJECT_SOURCE_DIR}/include)
install(TARGETS testEvaluateGrid DESTINATION bin)

#add_executable(testMPILatexGenerator testMPILatexGenerator.cpp)
#target_compile_features(testMPILatexGenerator PRIVATE cxx_std_17)

#target_link_libraries(testMPILatexGenerator PRIVATE latexGenerator_library sudoku_library grid_library stdc++fs)
#target_include_directories(testMPILatexGenerator PUBLIC ${PROJECT_SOURCE_DIR}/include)
#install(TARGETS testMPILatexGenerator DESTINATION bin)

add_executable(testLevel testLevel.cpp)
target_compile_features(testLevel PRIVATE cxx_std_17)

target_link_libraries(testLevel PRIVATE latexGenerator_library sudoku_library grid_library stdc++fs)
target_include_directories(testLevel PUBLIC ${PROJECT_SOURCE_DIR}/include)
install(TARGETS testLevel DESTINATION bin)

add_executable(testLevelInGeneration testLevelInGeneration.cpp)
target_compile_features(testLevelInGeneration PRIVATE cxx_std_17)

target_link_libraries(testLevelInGeneration PRIVATE latexGenerator_library sudoku_library grid_library stdc++fs)
target_include_directories(testLevelInGeneration PUBLIC ${PROJECT_SOURCE_DIR}/include)
install(TARGETS testLevelInGeneration DESTINATION bin)