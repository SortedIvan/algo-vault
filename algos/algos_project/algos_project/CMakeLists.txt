cmake_minimum_required(VERSION 3.23)
project(algos_project CXX)

# Add directories

add_subdirectory(include/Catch2)

# Create targets (libraries or executables)
add_executable(UnionFindTest 
	datastructs/union_find/test/test.cpp
	datastructs/union_find/union_find.cpp
)
add_executable(AlgoProject main.cpp datastructs/union_find/union_find.cpp)

# Include header files into the targets
target_include_directories(AlgoProject PRIVATE datastructs/union_find)
target_include_directories(UnionFindTest PRIVATE datastructs/union_find)

# Link libraries
target_link_libraries(UnionFindTest PRIVATE Catch2::Catch2WithMain)
