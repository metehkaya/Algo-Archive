class DataStream {
public:
    int val,k;
    int cntAll,cntVal;
    deque<int> q;
    DataStream(int value, int k) {
        cntAll = 0;
        cntVal = 0;
        this->k = k;
        this->val = value;
    }
    bool consec(int num) {
        if(cntAll == k) {
            if(q.front()==val)
                cntVal--;
            cntAll--;
            q.pop_front();
        }
        q.push_back(num);
        if(num == val)
            cntVal++;
        cntAll++;
        return cntVal == k;
    }
};
