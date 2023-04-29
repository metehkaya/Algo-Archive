class Solution {
public:
    int meetRequirement(int n, vector<vector<int>>& lights, vector<int>& req) {
        int curr = 0 , ans = 0;
        vector<int> add(n,0);
        for(auto v : lights) {
            int s = v[0]-v[1];
            int e = v[0]+v[1]+1;
            if(s < 0)
                curr++;
            else
                add[s]++;
            if(e < n)
                add[e]--;
        }
        for( int i = 0 ; i < n ; i++ ) {
            curr += add[i];
            ans += (curr >= req[i]);
        }
        return ans;
    }
};
