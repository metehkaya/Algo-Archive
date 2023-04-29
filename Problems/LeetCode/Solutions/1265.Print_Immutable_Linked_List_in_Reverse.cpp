class ImmutableListNode {
public:
    void printValue(); // print the value of the node.
    ImmutableListNode* getNext(); // return the next node.
};

class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        if(head == NULL)
            return;
        printLinkedListInReverse(head->getNext());
        head->printValue();
    }
};