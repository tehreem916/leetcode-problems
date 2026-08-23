class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> toRemove(nums.begin(), nums.end());

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = dummy;

        while (curr->next) {
            if (toRemove.count(curr->next->val))
                curr->next = curr->next->next;  // skip node
            else
                curr = curr->next;              // move forward
        }

        return dummy->next;
    }
};