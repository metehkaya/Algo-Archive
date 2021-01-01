class Node {
public:
    int val;
    Node* next;
    Node() {}
    Node(int _val) {
        val = _val;
        next = NULL;
    }
    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

class Solution {
public:
    Node* insert(Node* head, int val) {
        Node* newNode = new Node(val);
        if(head == NULL) {
            head = newNode;
            head->next = head;
        }
        else if(head->next == head) {
            head->next = newNode;
            newNode->next = head;
        }
        else {
            Node* tail = NULL;
            Node* curr = head;
            bool found = false;
            do {
                if(curr->val <= curr->next->val) {
                    if(val >= curr->val && val <= curr->next->val) {
                        newNode->next = curr->next;
                        curr->next = newNode;
                        found = true;
                        break;
                    }
                }
                else {
                    if(val >= curr->val || val <= curr->next->val) {
                        newNode->next = curr->next;
                        curr->next = newNode;
                        found = true;
                        break;
                    }
                }
                tail = curr;
                curr = curr->next;
            }while(curr != head);
            if(!found) {
                newNode->next = head;
                tail->next = newNode;
            }
        }
        return head;
    }
};