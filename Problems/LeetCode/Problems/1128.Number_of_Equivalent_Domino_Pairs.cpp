class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& arr) {
        int n = (int) arr.size();
        int ans = 0;
        map<pair<int,int>,int> hashh;
        map<pair<int,int>,int>::iterator iter;
        for( int i = 0 ; i < n ; i++ ) {
            int mn = arr[i][0];
            int mx = arr[i][1];
            if(mn > mx)
                swap(mn, mx);
            pair<int,int> p = make_pair(mn,mx);
            iter = hashh.find(p);
            if(iter == hashh.end())
                hashh.insert(make_pair(p,1));
            else {
                ans += iter->second;
                iter->second++;
            }
        }
        return ans;
    }
};