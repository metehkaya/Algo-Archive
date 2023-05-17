class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<bool> mark(n,false);
        int idx = 0 , i = 1;
        mark[idx] = true;
        while(true) {
            idx = (idx+i*k) % n;
            if(mark[idx])
                break;
            mark[idx] = true;
            i++;
        }
        vector<int> ans;
        for( int i = 0 ; i < n ; i++ )
            if(!mark[i])
                ans.push_back(i+1);
        return ans;
    }
};
