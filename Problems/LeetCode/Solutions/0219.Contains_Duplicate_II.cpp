class Solution {
public:
    map<int,int> mp;
    bool containsNearbyDuplicate(vector<int>& ar, int k) {
        int n = ar.size();
        k++;
        k = min(n,k);
        for( int i = 0 ; i < k ; i++ )
            if(++mp[ar[i]] > 1)
                return true;
        for( int i = k ; i < n ; i++ ) {
            mp[ar[i-k]]--;
            if(++mp[ar[i]] > 1)
                return true;
        }
        return false;
    }
};