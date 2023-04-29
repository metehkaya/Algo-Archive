class Solution {
public:
    vector<int> intersection(vector<vector<int>>& ar) {
        int n = ar.size();
        vector<int> ans;
        map<int,int> cnt;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < ar[i].size() ; j++ )
                cnt[ar[i][j]]++;
        for(auto it : cnt)
            if(it.second == n)
                ans.push_back(it.first);
        return ans;
    }
};
