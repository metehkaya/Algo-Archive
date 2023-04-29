class Solution {
public:
    int n;
    int ans[40];
    bool mark[21];
    bool f(int idx) {
        if(idx == 2*n)
            return true;
        if(ans[idx])
            return f(idx+1);
        for( int i = n ; i >= 1 ; i-- )
            if(!mark[i]) {
                if(i == 1) {
                    ans[idx] = 1;
                    mark[i] = true;
                    if(f(idx+1))
                        return true;
                    ans[idx] = 0;
                    mark[i] = false;
                }
                else if(idx+i < 2*n && !ans[idx+i]) {
                    ans[idx] = ans[idx+i] = i;
                    mark[i] = true;
                    if(f(idx+1))
                        return true;
                    ans[idx] = ans[idx+i] = 0;
                    mark[i] = false;
                }
            }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        this->n = n;
        f(1);
        vector<int> v;
        for( int i = 1 ; i < 2*n ; i++ )
            v.push_back(ans[i]);
        return v;
    }
};