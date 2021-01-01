class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return NULL;
        map<Node*,Node*> mp;
        Node* newHead = new Node(head->val);
        Node* tail = head;
        Node* newTail = newHead;
        while(tail->next) {
            mp[tail] = newTail;
            Node* newNode = new Node(tail->next->val);
            newTail->next = newNode;
            tail = tail->next;
            newTail = newTail->next;
        }
        mp[tail] = newTail;
        tail = head;
        newTail = newHead;
        while(tail) {
            if(tail->random)
                newTail->random = mp[tail->random];
            tail = tail->next;
            newTail = newTail->next;
        }
        return newHead;
    }
};