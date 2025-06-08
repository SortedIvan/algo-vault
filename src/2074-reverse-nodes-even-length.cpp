class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        vector<vector<ListNode*>> nodeGroups;
        
        int nodesToCollect = 1;
        ListNode* currHead = head;  // Track the current head for traversal
    
        while (true) {
            vector<ListNode*> group;
            collectNodes(group, currHead, nodesToCollect);
            
            if (!group.empty()) {
                currHead = group[group.size() - 1]->next;
                nodeGroups.push_back(group);
            }
            else {
                break;
            }
            
            if (group.size() < nodesToCollect) {
                break;
            }

            nodesToCollect++;
        }

        // We need a dummy to reconnect the reversed groups easily
        ListNode dummy(0);
        ListNode* prevTail = &dummy;

        for (int i = 0; i < nodeGroups.size(); ++i) {
            vector<ListNode*>& group = nodeGroups[i];

            if (group.size() % 2 == 0) {
                // Reverse this group in place
                // reverse(prev, curr, end)
                // prev = nullptr, curr = first node in group, end = node after last node in group
                ListNode* reversedHead = reverse(nullptr, group[0], group.back()->next);
                
                // Connect previous group tail to reversed head
                prevTail->next = reversedHead;
                prevTail = group[0]; // after reversal, the first node becomes the tail
                
                // Tail's next should already point to the next group's head (group.back()->next)
            } else {
                // Group not reversed, just connect as is
                prevTail->next = group[0];
                prevTail = group.back();
            }
        }

        prevTail->next = nullptr; // Terminate list properly

        return dummy.next;
    }


    void collectNodes(vector<ListNode*>& result, ListNode* node, int nodesToCollect) {
        if (!node || !nodesToCollect) {
            return;
        }

        result.push_back(node);

        if (node->next) {
            collectNodes(result, node->next, nodesToCollect - 1);
        }
    }

    ListNode* reverse(ListNode* prev, ListNode* curr, ListNode* end) {
        if (!curr || curr == end) {
            return prev;
        }

        ListNode* temp = curr->next;
        curr->next = prev;
        return reverse(curr, temp, end);
    }
};
