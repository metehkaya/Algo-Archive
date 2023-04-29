#define fi first
#define se second

class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        int n = creators.size();
        long long mx = 0;
        map<string,long long> total;
        map<string,pair<string,int>> mp;
        for( int i = 0 ; i < n ; i++ ) {
            string c = creators[i];
            total[c] += views[i];
            mx = max(mx,total[c]);
            auto it = mp.find(c);
            if(it == mp.end())
                mp[c] = make_pair(ids[i],views[i]);
            else {
                pair<string,int> p = it->se;
                if(views[i] > p.se || (views[i] == p.se && ids[i] < p.fi))
                    mp[c] = make_pair(ids[i],views[i]);
            }
        }
        vector<vector<string>> ans;
        for(auto it : total)
            if(it.se == mx)
                ans.push_back(vector<string>{it.fi,mp[it.fi].fi});
        return ans;
    }
};
