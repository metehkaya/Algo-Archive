class Solution {
public:
    int maxFrequencyElements(vector<int>& v) {
        int n = v.size();
        map<int,int> mp;
        vector<int> cnt(n+1,0);
        for(int x : v)
            mp[x]++;
        for(auto it : mp)
            cnt[it.second]++;
        for( int i = n ; i >= 1 ; i-- )
            if(cnt[i])
                return i*cnt[i];
        return -1;
    }
};
