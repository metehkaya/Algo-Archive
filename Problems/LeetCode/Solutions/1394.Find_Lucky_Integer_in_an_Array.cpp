class Solution {
public:
    int findLucky(vector<int>& ar) {
        map<int,int> cnt;
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ )
            cnt[ar[i]]++;
        int ans = -1;
        for( auto it = cnt.begin() ; it != cnt.end() ; it++ )
            if(it->first == it->second)
                ans = max( ans , it->first );
        return ans;
    }
};