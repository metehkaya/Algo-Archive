class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        int n = pos.size();
        vector<pair<int,double>> v;
        for( int i = 0 ; i < n ; i++ )
            v.push_back(make_pair(pos[i],(double)(target-pos[i])/speed[i]));
        sort(v.begin(),v.end());
        int ans = 0;
        double t = 0;
        for( int i = n-1 ; i >= 0 ; i-- )
            if(v[i].second > t) {
                ans++;
                t = v[i].second;
            }
        return ans;
    }
};
