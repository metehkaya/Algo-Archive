class Solution {
public:
    int arrayNesting(vector<int>& ar) {
        int n = ar.size() , ans = 0;
        vector<bool> mark(n,false);
        for( int i = 0 ; i < n ; i++ )
            if(!mark[i]) {
                int j = i;
                int cnt = 0;
                while(!mark[j]) {
                    cnt++;
                    mark[j] = true;
                    j = ar[j];
                }
                ans = max(ans,cnt);
            }
        return ans;
    }
};