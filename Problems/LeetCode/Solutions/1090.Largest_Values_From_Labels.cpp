class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        int n = labels.size();
        vector<pair<int,int>> v;
        for( int i = 0 ; i < n ; i++ )
            v.push_back( make_pair( values[i] , labels[i] ) );
        sort( v.begin() , v.end() );
        int ans = 0;
        unordered_map<int,int> hashh;
        unordered_map<int,int>::iterator mit;
        for( int i = n-1 ; i >= 0 && num_wanted > 0 ; i-- ) {
            int val = v[i].first;
            int key = v[i].second;
            mit = hashh.find(key);
            if(mit == hashh.end() || mit->second < use_limit) {
                num_wanted--;
                hashh[key]++;
                ans += val;
            }
        }
        return ans;
    }
};