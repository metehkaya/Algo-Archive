class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int>last(26,-1);
        int n = S.length();
        for( int i = 0 ; i < n ; i++ )
            last[S[i]-'a'] = i;
        vector<pair<int,int>> intervals;
        for( int l=0 , r=-1 ; l < n ; l++ ) {
            int c = S[l] - 'a';
            if(r < l)
                intervals.push_back(make_pair(l,l));
            r = max(r, last[c]);
            intervals[intervals.size()-1].second = r;
        }
        vector<int> ans;
        for( int i = 0 ; i < intervals.size() ; i++ )
            ans.push_back( intervals[i].second - intervals[i].first + 1 );
        return ans;
    }
};