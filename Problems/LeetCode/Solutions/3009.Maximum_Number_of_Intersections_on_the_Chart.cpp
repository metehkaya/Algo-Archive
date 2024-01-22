class Solution {
public:
    int maxIntersectionCount(vector<int>& v) {
        int n = 0;
        map<int,int> mp;
        set<int> s(v.begin(), v.end());
        for(int x : s)
            mp[x] = n++;
        vector<int> add(3*n,0);
        for( int i = 0 ; i < v.size() ; i++ ) {
            int x = mp[v[i]];
            add[3*x+1]++;
            add[3*x+2]--;
        }
        for( int i = 0 ; i < v.size()-1 ; i++ ) {
            int x = mp[v[i]] , y = mp[v[i+1]];
            if(x > y)
                swap(x,y);
            add[3*x+2]++;
            add[3*y+1]--;
        }
        int ans = 0 , curr = 0;
        for(int x : add) {
            curr += x;
            ans = max(ans,curr);
        }
        return ans;
    }
};
