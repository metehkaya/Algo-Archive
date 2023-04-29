class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<double> v;
        int n = dist.size();
        for( int i = 0 ; i < n ; i++ )
            v.push_back((double)dist[i]/speed[i]);
        sort(v.begin(),v.end());
        for( int i = 0 ; i < n ; i++ )
            if(i >= v[i])
                return i;
        return n;
    }
};