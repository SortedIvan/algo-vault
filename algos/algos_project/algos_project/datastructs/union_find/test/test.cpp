#include <catch2/catch_test_macros.hpp>
#include <string>
#include "../union_find/union_find.hpp"
#include <vector>
#include <iostream>

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

TEST_CASE("Union find correctly adds two groups together", "[union_find]") {
	// Initialize
	std::vector<int> unionFindElements{ 0,1,2,3,4 };
	REQUIRE(!containsNegativeNumbers(unionFindElements));
	UnionFind unionFind(unionFindElements);

	// Set up initial groupings, make 0 be the root of all
	unionFind.union_elements(0, 1);
	unionFind.union_elements(0, 2);
	unionFind.union_elements(0, 3);
	unionFind.union_elements(0, 4);

	// Then, if we introduce a new element 5 and try to union it to any of them, 0 should be the root
	unionFind.union_elements(3, 5);
	REQUIRE(unionFind.find(5) == 0);
}

TEST_CASE("Union find behaves correctly when some elements don't exist", "[union_find]") {
	SECTION("when two elements added that don't exist, make x parent of y") {
		UnionFind uf({});
		uf.union_elements(0, 1);
		REQUIRE(uf.find(1) == 0);
		REQUIRE(uf.find(0) == 0);
	}

	SECTION("when one passed element does not exist, make the other the parent of it") {
		UnionFind uf({1});
		uf.union_elements(0, 1);
		REQUIRE(uf.find(0) == 1);
		REQUIRE(uf.find(1) == 1);
	}
}




