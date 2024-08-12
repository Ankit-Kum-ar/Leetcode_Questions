/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0) return head;
    
        int cnt = 0;
        ListNode* temp = head;
        while(temp != NULL) {
            cnt++;
            temp = temp->next;
        }
        if(cnt == 1) return head;
        if(k > cnt) k = k%cnt;
        if(k == cnt) return head;

        temp = head;
        ListNode* last = head;
        while(last->next != NULL) {
            last = last->next;
        }

        for(int i=1;i<(cnt-k);i++) {
            temp = temp->next;
        }
        
        last->next = head;
        head = temp->next;
        temp->next = NULL;        
        return head;

    }
};