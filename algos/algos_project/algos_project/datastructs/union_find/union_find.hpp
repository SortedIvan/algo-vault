#pragma once
#include <unordered_map>

/*
	@summary
	Build subtrees where the root is the representative of that group
	Define 3 operations:
		- Union(x,y): Union groups x and y
		- Find(x): Find the representative of the group where x belongs to
		- Parent(x): Get the parent of x. The root of the component tree is a parent of itself
	We can keep a map/array to represent the parent/node relationship
*/
class UnionFind {
private:
	// to_do
	std::unordered_map<int,int> parentMap;
	std::unordered_map<int,int> groupSize; // keep a track for a group's 
public:
	const std::unordered_map<int, int>& parentMapNonModifiable();
	UnionFind(std::vector<int> elements);
	int find(int x);
	void union_elements(int x, int y);
};