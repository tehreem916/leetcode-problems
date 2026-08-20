class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;   // copy next node's value into this node
        node->next = node->next->next; // skip over the next node (unlink it)
    }
};