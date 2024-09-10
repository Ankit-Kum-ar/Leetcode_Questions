class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL || head == NULL) return NULL;

        ListNode* fast = head;
        ListNode* slow = head;

        while(fast->next->next != NULL and fast->next->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = slow->next->next;

        return head;
    }
};