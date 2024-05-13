/*
    Approach :- 
    1. Count the number of nodes that list consist.
    2. Now find the middle by (count/2).
    3. Apply a loop from 1 to middle and get the middle node.
    4. return that middle node.
*/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL) {
            count++;
            temp = temp->next;
        }
        temp = head;
        int middle = count/2;
        for(int i=1;i<=middle;i++) {
            temp = temp->next;
        }
        return temp;
    }
};