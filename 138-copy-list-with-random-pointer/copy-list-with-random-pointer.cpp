class Solution {
public:
    Node* copyRandomList(Node* head) {
        // 1. Make deep copy of List without connecting random pointers
        Node* dummy = new Node(0);
        Node* temp = head;
        Node* tempC = dummy;
        while(temp != NULL) {
            Node* a = new Node(temp->val);
            tempC->next = a;
            tempC = tempC->next;
            temp = temp->next;
        }

        Node* a = head;
        Node* b = dummy->next;

        // 2. Make a map of <original, duplicate> to map random pointers
        Node* tempA = a;
        Node* tempB = b;
        unordered_map<Node*, Node*> m;
        while(tempA != NULL) {
            m[tempA] = tempB;
            tempA = tempA->next;
            tempB = tempB->next;
        }

        for(auto x:m) {
            Node* o = x.first;
            Node* d = x.second;
            if(o->random != NULL) {
                d->random = m[o->random];
            }
        }

        return b;

    }
};