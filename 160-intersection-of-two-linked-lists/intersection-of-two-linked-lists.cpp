class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 1, len2 = 1;
        int diff;
        ListNode* tempA = headA;
        ListNode* tempB = headB;

        while(tempA->next != NULL) {
            len1++;
            tempA = tempA->next;
        }

        while(tempB->next != NULL) {
            len2++;
            tempB = tempB->next;
        }

        diff = abs(len1 - len2);

        if(len1 > len2) {
            for(int i=1;i<=diff;i++) {
                headA = headA->next;
            }
        }
        else  {
            for(int i=1;i<=diff;i++) {
                headB = headB->next;
            }
        }

        while(headA != NULL and headB != NULL) {
            if(headA == headB) {
                if(headA->val == headB->val) return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }

        return NULL;
    }
};