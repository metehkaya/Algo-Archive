class Solution {
public:
    int distinctAverages(vector<int>& v) {
        int n = v.size();
        set<int> s;
        sort(v.begin(),v.end());
        for( int i = 0 ; i < n/2 ; i++ )
            s.insert(v[i]+v[n-1-i]);
        return (int) s.size();
    }
};
