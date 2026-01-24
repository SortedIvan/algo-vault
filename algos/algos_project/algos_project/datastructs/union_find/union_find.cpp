#include "./union_find.hpp"

UnionFind::UnionFind(std::vector<int> elements) {
	for (int i = 0; i < elements.size(); ++i) {
		parentMap.insert({elements[i], elements[i]});
	}
}

/*	@summary
	Finds the representative of the group where x belongs to
*/
int UnionFind::find(int x) {
	if (parentMap.find(x) == parentMap.end()) {
		return -1;
	} 
	
	int parent = parentMap[x];

	if (parent == x) {
		return x;
	}

	parentMap[x] = find(parentMap[x]);
	return parentMap[x];
}

/*	@summary
	Union two elements and set their parents as the representative of the group
	if the two provided elements are not part of any group, create a new group for them	and make x representative	
*/
void UnionFind::union_elements(int x, int y) {
	int parent_x = find(x);
	int parent_y = find(y);
	
	if (parent_x < 0 && parent_y < 0) {
		parentMap[x] = x;
		parentMap[y] = x;
		return;
	}

	if (parent_x == parent_y) {
		return;
	}

	if (parent_x < 0 && parent_y >= 0) {
		// parent_y exists, parent_x doesn't. 
		// Attach x to y
		parentMap[x] = parent_y;
	}
	else if (parent_y < 0 && parent_x >= 0) {
		parentMap[y] = parent_x;
	}
	else {
		parentMap[parent_x] = parent_y;
	}
}

const std::unordered_map<int, int>& UnionFind::parentMapNonModifiable() {
	return parentMap;
}