class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        heaters.push_back(0);
        heaters.push_back(1e9+1);
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int n = houses.size();
        int m = heaters.size();
        int ans = 0;
        for( int i = 0 , l = 0 , r = 0 ; i < n ; i++ ) {
            while(l+1 < m && heaters[l+1] <= houses[i])
                l++;
            while(r < m && heaters[r] < houses[i])
                r++;
            int diff = INT_MAX;
            if(l > 0)
                diff = houses[i]-heaters[l];
            if(r < m-1)
                diff = min(diff,heaters[r]-houses[i]);
            ans = max(ans,diff);
        }
        return ans;
    }
};
