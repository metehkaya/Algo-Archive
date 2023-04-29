class Solution {
public:
    int minimumCardPickup(vector<int>& ar) {
        int n = ar.size() , ans = INT_MAX;
        map<int,int> last;
        map<int,int>::iterator it;
        for( int i = 0 ; i < n ; i++ ) {
            it = last.find(ar[i]);
            if(it != last.end())
                ans = min(ans,i-it->second+1);
            last[ar[i]] = i;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
