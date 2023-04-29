class MyCircularQueue {
public:
    int head,tail,size,cnt;
    vector<int>v;
    MyCircularQueue(int k) {
        cnt=0;
        head=0;
        tail=0;
        size=k;
        v.resize(k);
    }
    bool enQueue(int value) {
        if(cnt == size)
            return false;
        cnt++;
        v[tail] = value;
        tail = (tail+1) % size;
        return true;
    }
    bool deQueue() {
        if(!cnt)
            return false;
        cnt--;
        head = (head+1) % size;
        return true;
    }
    int Front() {
        if(cnt > 0)
            return v[head];
        return -1;
    }
    int Rear() {
        if(cnt > 0)
            return v[(tail+size-1)%size];
        return -1;
    }
    bool isEmpty() {
        return cnt == 0;
    }
    bool isFull() {
        return cnt == size;
    }
};
