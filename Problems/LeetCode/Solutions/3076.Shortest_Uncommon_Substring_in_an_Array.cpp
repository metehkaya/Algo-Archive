class Solution {
public:
    static const int maxlen = 20;
    vector<string> shortestSubstrings(vector<string>& arr) {
        int n = arr.size() , m = arr[0].size();
        map<string, set<int>> mp[maxlen];
        for( int i = 0 ; i < n ; i++ ) {
            int len = arr[i].size();
            for( int j = 0 ; j < len ; j++ ) {
                string s = "";
                for( int k = j ; k < len ; k++ ) {
                    s.push_back(arr[i][k]);
                    mp[k-j][s].insert(i);
                }
            }
        }
        vector<string> ans(n, "");
        for( int l = 0 ; l < maxlen ; l++ )
            for(auto it : mp[l])
                if(it.second.size() == 1) {
                    int id = *it.second.begin();
                    if(ans[id] == "")
                        ans[id] = it.first;
                }
        return ans;
    }
};
