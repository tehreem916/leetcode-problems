class Solution {
public:
    // reverse linked list 
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        //  find middle
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        //  reverse second half
        ListNode* secondHalf = reverse(slow);

        //  compare both halves
        ListNode* p1 = head;
        ListNode* p2 = secondHalf;
        bool result = true;

        while (p2) {           
            if (p1->val != p2->val) {
                result = false;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        return result;
    }
};