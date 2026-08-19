class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;         // move 1 step
            fast = fast->next->next;   // move 2 steps
        }

        return slow;
    }
};