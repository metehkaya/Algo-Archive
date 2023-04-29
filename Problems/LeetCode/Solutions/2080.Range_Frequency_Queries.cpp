class RangeFreqQuery {
public:
    map<int,vector<int>> mp;
    RangeFreqQuery(vector<int>& ar) {
        for( int i = 0 ; i < ar.size() ; i++ )
            mp[ar[i]].push_back(i);
    }
    int query(int left, int right, int value) {
        if(mp.find(value) == mp.end())
            return 0;
        int l = lower_bound(mp[value].begin(),mp[value].end(),left) - mp[value].begin();
        int r = upper_bound(mp[value].begin(),mp[value].end(),right) - mp[value].begin();
        return r-l;
    }
};
