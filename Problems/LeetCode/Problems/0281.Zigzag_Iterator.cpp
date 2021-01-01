class ZigzagIterator {
public:
    int i,j;
    int n,m;
    int turn;
    vector<int> v1,v2;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        i = j = 0;
        this->v1 = v1;
        this->v2 = v2;
        n = v1.size();
        m = v2.size();
        turn = (n > 0) ? 0 : 1;
    }
    int next() {
        int ans;
        if(turn == 0) {
            ans = v1[i++];
            if(j < m)
                turn = 1;
        }
        else {
            ans = v2[j++];
            if(i < n)
                turn = 0;
        }
        return ans;
    }
    bool hasNext() {
        return (i < n) || (j < m);
    }
};