class FirstUnique {
public:
    FirstUnique(vector<int>& ar) {
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ ) {
            Q.push(ar[i]);
            hashCnt[ar[i]]++;
        }
    }
    int showFirstUnique() {
        while(!Q.empty()) {
            int value = Q.front();
            if(hashCnt[value] > 1)
                Q.pop();
            else
                break;
        }
        if(Q.empty())
            return -1;
        return Q.front();
    }
    void add(int value) {
        Q.push(value);
        hashCnt[value]++;
    }
private:
    queue<int> Q;
    unordered_map<int,int> hashCnt;
};