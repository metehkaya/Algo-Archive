typedef vector<int> vi;
typedef vector<vi> vii;

class Solution {
public:
    vi topKFrequent(vi& ar, int k) {
        int n = ar.size();
        vii nums(n+1);
        map<int,int> cnt;
        for( int i = 0 ; i < n ; i++ )
            cnt[ar[i]]++;
        for( auto it = cnt.begin() ; it != cnt.end() ; it++ )
            nums[it->second].push_back(it->first);
        vector<int> ans;
        for( int i = n ; k && i >= 1 ; i-- )
            for( int j = 0 ; j < nums[i].size() ; j++ ) {
                k--;
                ans.push_back(nums[i][j]);
            }
        return ans;
    }
};