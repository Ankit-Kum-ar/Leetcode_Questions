class Solution {
public:
    ListNode* mergeLists(ListNode* a, ListNode* b) {
        if(a == NULL && b == NULL) return NULL;
        if(a == NULL) return b;
        if(b == NULL) return a;

        ListNode* c = new ListNode(100);
        ListNode* temp = c;

        while(a != NULL and b != NULL) {
            if(a->val < b->val) {
                temp->next = a;
                a = a->next;
                temp = temp->next;
            }
            else {
                temp->next = b;
                b = b->next;
                temp = temp->next;
            }
        }

        if(a != NULL) temp->next = a;
        if(b != NULL) temp->next = b;

        c = c->next;
        return c;        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        
        while(lists.size() > 1) {
            ListNode* a = lists[0];
            lists.erase(lists.begin());
            ListNode* b = lists[0];
            lists.erase(lists.begin());

            ListNode* c = mergeLists(a, b);
            lists.push_back(c);
        }
        return lists[0];
    }
};