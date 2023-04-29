class MyNode {
public:
    int val;
    MyNode* next;
    MyNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class MyLinkedList {
public:
    int sz;
    MyNode* head;
    MyLinkedList() {
        sz = 0;
        head = NULL;
    }
    int get(int index) {
        if(index >= sz)
            return -1;
        MyNode* node = head;
        while(index--)
            node = node->next;
        return node->val;
    }
    void addAtHead(int val) {
        MyNode* exHead = head;
        head = new MyNode(val);
        head->next = exHead;
        sz++;
    }
    void addAtTail(int val) {
        if(head == NULL)
            addAtHead(val);
        else {
            MyNode* tail = head;
            while(tail->next)
                tail = tail->next;
            tail->next = new MyNode(val);
            sz++;
        }
    }
    void addAtIndex(int index, int val) {
        if(index > sz)
            return;
        else if(index == 0)
            addAtHead(val);
        else if(index == sz)
            addAtTail(val);
        else {
            MyNode* prevNode = NULL;
            MyNode* node = head;
            while(index--) {
                prevNode = node;
                node = node->next;
            }
            MyNode* newNode = new MyNode(val);
            prevNode->next = newNode;
            newNode->next = node;
            sz++;
        }
    }
    void deleteAtIndex(int index) {
        if(index >= sz)
            return;
        MyNode* prevNode = NULL;
        MyNode* node = head;
        while(index--) {
            prevNode = node;
            node = node->next;
        }
        MyNode* nextNode = node->next;
        delete node;
        node = NULL;
        if(prevNode)
            prevNode->next = nextNode;
        sz--;
        if(!prevNode)
            head = nextNode;
    }
};