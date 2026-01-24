#include <catch2/catch_test_macros.hpp>
#include <string>
#include "../union_find/union_find.hpp"
#include <vector>

bool containsNegativeNumbers(const std::vector<int>& vec) {
	for (int i = 0; i < vec.size(); ++i) {
		if (vec[i] < 0) {
			return true;
		}
	}

	return false;
}

TEST_CASE("Union find initializes correctly", "[union_find]") {
	// Set up
	std::vector<int> unionFindElements{0,1,2,3,4};
	const size_t initialUnionFindSize = 5;

	REQUIRE(unionFindElements.size() == initialUnionFindSize);
	REQUIRE(!containsNegativeNumbers(unionFindElements));

	SECTION("when initialized, there are 5 unique nodes in parentMap") {
		UnionFind unionFind(unionFindElements);
		REQUIRE(unionFind.parentMapNonModifiable().size() == initialUnionFindSize);
	}

	SECTION("when initialized, every node should be a parent of itself") {
		UnionFind unionFind(unionFindElements);
		
		for (int i = 0; i < unionFindElements.size(); ++i) {
			REQUIRE(unionFind.find(unionFindElements[i]) == unionFindElements[i]);
		}
	}
}