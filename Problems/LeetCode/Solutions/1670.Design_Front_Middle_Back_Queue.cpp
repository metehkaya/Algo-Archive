class FrontMiddleBackQueue {
public:
    int n;
    vector<int> v;
    FrontMiddleBackQueue() {
        n = 0;
    }
    void pushFront(int val) {
        n++;
        v.insert(v.begin(), val);
    }
    void pushMiddle(int val) {
        int idx = n/2;
        vector<int> v2;
        for( int i = 0 ; i < idx ; i++ )
            v2.push_back(v[i]);
        v2.push_back(val);
        for( int i = idx ; i < n ; i++ )
            v2.push_back(v[i]);
        v = v2;
        n++;
    }
    void pushBack(int val) {
        n++;
        v.push_back(val);
    }
    int popFront() {
        if(!n)
            return -1;
        n--;
        int res = v.front();
        v.erase(v.begin());
        return res;
    }
    int popMiddle() {
        if(!n)
            return -1;
        int idx = (n-1)/2;
        int res = v[idx];
        vector<int> v2;
        for( int i = 0 ; i < idx ; i++ )
            v2.push_back(v[i]);
        for( int i = idx+1 ; i < n ; i++ )
            v2.push_back(v[i]);
        v = v2;
        n--;
        return res;
    }
    int popBack() {
        if(!n)
            return -1;
        n--;
        int res = v.back();
        v.pop_back();
        return res;
    }
};