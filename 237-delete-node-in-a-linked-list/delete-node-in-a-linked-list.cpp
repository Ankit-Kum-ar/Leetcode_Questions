/*
    Approach :- The approach is tricky in this problem. 
    The problem says that don't remove node from memory now
    this is essence of problem that we should not remove 
    linking of node, infact we just simply remove the value
    from that node. For that we apply a loop where we insert
    the value of next node to current node and when we reach
    second last node make it's next => NULL.
*/
class Solution {
public:
    void deleteNode(ListNode* node) {
        while(node->next->next != NULL) {
            node->val = node->next->val;
            node = node->next;
        }
        node->val = node->next->val;
        node->next = NULL;
    }
};