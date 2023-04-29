class Solution {
public:
    int shortestSequence(vector<int>& ar, int k) {
        int n = ar.size();
        if(k == 1)
            return n+1;
		vector<int> indices[k];
        for( int i = 0 ; i < n ; i++ )
            indices[ar[i]-1].push_back(i);
        int idx = 0;
        for( int len = 1 ; len <= n ; len++ ) {
            int nxt_idx = -1;
            for( int i = 0 ; i < k ; i++ ) {
                vector<int>::iterator it = lower_bound(indices[i].begin(), indices[i].end(), idx);
                if(it == indices[i].end())
                    return len;
                nxt_idx = max(nxt_idx, (*it));
            }
            idx = nxt_idx+1;
        }
        return n+1;
    }
};
