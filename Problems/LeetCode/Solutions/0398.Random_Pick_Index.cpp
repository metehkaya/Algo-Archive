class Solution {
public:
    int n;
    map<int,vector<int>> mp;
    Solution(vector<int>& ar) {
        n = ar.size();
        for( int i = 0 ; i < n ; i++ )
            mp[ar[i]].push_back(i);
    }
    int pick(int x) {
        map<int,vector<int>>::iterator it = mp.find(x);
        int sz = it->second.size();
        int id = rand() % sz;
        return it->second[id];
    }
};