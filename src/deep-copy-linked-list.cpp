/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

#include <map>
#include <utility>

class Solution {
public:
    Node* copyRandomList(Node* head) {
        std::map<Node*, int> oldListIndices;
        std::map<int, Node*> randomPointerMap;
        std::map<int, Node*> newListIndices; 

        int numberOfNodesCount = 0;
        Node* result = nullptr;

        populateRandomPointerMapAndList(numberOfNodesCount, randomPointerMap, head, result, newListIndices, oldListIndices);
        setRandomPointersInResultList(randomPointerMap, oldListIndices, newListIndices, 0, result);

        return result;

    }

    void populateRandomPointerMapAndList(int& numberOfNodesCount, std::map<int, Node*>& randomPointerMap, Node* curr, Node*& result, map<int, Node*>& newListIndices, std::map<Node*, int>& oldListIndices)
    {
        if (!curr)
        {
            return;
        }

        Node* node = new Node(curr->val);
        result = node;

        randomPointerMap.insert({numberOfNodesCount, curr->random});
        newListIndices.insert({numberOfNodesCount,node});
        oldListIndices.insert({curr, numberOfNodesCount});

        numberOfNodesCount++;

        populateRandomPointerMapAndList(numberOfNodesCount, randomPointerMap, curr->next, result->next, newListIndices, oldListIndices);

    }

    void setRandomPointersInResultList(std::map<int, Node*>& randomPointerMap, map<Node*, int> oldIndexMap,
     map<int, Node*> newIndexMap, int counter, Node*& result) 
    {
        if (!result)
        {
            return;
        }

        Node* toFetch = randomPointerMap[counter];

        if (!toFetch)
        {
            result->random = nullptr;
        }
        else
        {
            int indexToPut = oldIndexMap[toFetch];
            Node* actualNode = newIndexMap[indexToPut];
            result->random = actualNode;
        }

        counter++;
        setRandomPointersInResultList(randomPointerMap, oldIndexMap, newIndexMap, counter, result->next);

    }

};
