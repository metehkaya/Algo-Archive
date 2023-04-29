class MyCircularDeque {
public:
    int sz;
    deque<int> q;
    MyCircularDeque(int k) {
        this->sz = k;
        q.clear();
    }
    bool insertFront(int value) {
        if(sz) {
            sz--;
            q.push_front(value);
            return true;
        }
        return false;
    }
    bool insertLast(int value) {
        if(sz) {
            sz--;
            q.push_back(value);
            return true;
        }
        return false;
    }
    bool deleteFront() {
        if(!q.empty()) {
            sz++;
            q.pop_front();
            return true;
        }
        return false;
    }
    bool deleteLast() {
        if(!q.empty()) {
            sz++;
            q.pop_back();
            return true;
        }
        return false;
    }
    int getFront() {
        return q.empty() ? -1 : q.front();
    }
    int getRear() {
        return q.empty() ? -1 : q.back();
    }
    bool isEmpty() {
        return q.empty();
    }
    bool isFull() {
        return !sz;
    }
};
