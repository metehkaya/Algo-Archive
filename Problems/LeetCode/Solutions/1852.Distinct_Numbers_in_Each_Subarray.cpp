class Solution {
public:
    vector<int> distinctNumbers(vector<int>& v, int k) {
        int n = v.size() , cnt = 0;
        map<int,int> mp;
        for( int i = 0 ; i < k ; i++ )
            if(++mp[v[i]] == 1)
                cnt++;
        vector<int> ans({cnt});
        for( int i = k ; i < n ; i++ ) {
            if(++mp[v[i]] == 1)
                cnt++;
            if(--mp[v[i-k]] == 0)
                cnt--;
            ans.push_back(cnt);
        }
        return ans;
    }
};
