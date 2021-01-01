class Solution {
public:
    vector<int> avoidFlood(vector<int>& ar) {
        int n = ar.size();
        set<int> s;
        map<int,int> idx;
        vector<int> add(n,-1);
        for( int i = n-1 ; i >= 0 ; i-- ) {
            auto it = idx.find(ar[i]);
            if(it != idx.end())
                add[i] = it->second;
            idx[ar[i]] = i;
        }
        vector<int> ans;
        for( int i = 0 ; i < n ; i++ ) {
            if(ar[i] == 0) {
                if(s.empty())
                    ans.push_back(1);
                else {
                    int k = *s.begin();
                    if(k < i) {
                        ans.clear();
                        return ans;
                    }
                    ans.push_back(ar[k]);
                    s.erase(s.begin());
                }
            }
            else {
                ans.push_back(-1);
                if(add[i] != -1)
                    s.insert(add[i]);
            }
        }
        if(!s.empty())
            ans.clear();
        return ans;
    }
};