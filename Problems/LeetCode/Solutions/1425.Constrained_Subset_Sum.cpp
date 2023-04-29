class Solution {
public:
    int constrainedSubsetSum(vector<int>& ar, int k) {
        int n = ar.size();
        deque<pair<int,int>> q;
        int ans = INT_MIN;
        for( int i = 0 ; i < n ; i++ ) {
            if(!q.empty() && i - q.front().second > k)
                q.pop_front();
            if(q.empty()) {
                if(ar[i] > 0)
                    q.push_back(make_pair(ar[i],i));
                ans = max( ans , ar[i] );
            }
            else {
                int val = q.front().first + ar[i];
                ans = max( ans , val );
                while(!q.empty() && val >= q.back().first)
                    q.pop_back();
                if(val > 0)
                    q.push_back(make_pair(val,i));
            }
        }
        return ans;
    }
};