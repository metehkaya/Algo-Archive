class Solution {
public:
    vector<int> recoverArray(vector<int>& ar) {
        int n = ar.size()/2;
        sort(ar.begin(),ar.end());
        vector<int> ans(2*n);
        for( int i = 1 ; i < 2*n ; i++ ) {
            int diff = ar[i]-ar[0];
            if(!diff || diff%2)
                continue;
            int k = diff/2;
            int id = 0;
            queue<int> q;
            for( int j = 0 ; j < 2*n ; j++ ) {
                int wait = (q.empty() ? -1 : q.front());
                if(ar[j] != wait) {
                    ans[id++] = ar[j]+k;
                    q.push(ar[j]+2*k);
                }
                else
                    q.pop();
            }
            if(q.empty())
                break;
        }
        ans.resize(n);
        return ans;
    }
};
