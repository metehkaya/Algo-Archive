class Solution {
public:
    int maxOperations(vector<int>& ar, int k) {
        map<int,int> mp;
        int n = ar.size() , ans = 0;
        for( int i = 0 ; i < n ; i++ )
            mp[ar[i]]++;
        for(auto it : mp) {
            int x = it.first;
            int xc = it.second;
            int y = k-x;
            if(x < y) {
                auto it2 = mp.find(y);
                if(it2 != mp.end())
                    ans += min(xc,it2->second);
            }
            else if(x == y)
                ans += xc/2;
        }
        return ans;
    }
};