class Solution {
public:
    int mostFrequent(vector<int>& ar, int key) {
        int n = ar.size();
        map<int,int> mp;
        int best = -1 , ans;
        for( int i = 0 ; i < n-1 ; i++ )
            if(ar[i] == key) {
                int val = ar[i+1];
                if(++mp[val] > best)
                    ans = val , best = mp[val];
            }
        return ans;
    }
};
