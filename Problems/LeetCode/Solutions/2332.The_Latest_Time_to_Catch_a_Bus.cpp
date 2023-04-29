class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(),buses.end());
        sort(passengers.begin(),passengers.end());
        int n = buses.size();
        int m = passengers.size();
        set<int> all_passengers;
        for( int i = 0 ; i < m ; i++ )
            all_passengers.insert(passengers[i]);
        vector<int> possible;
        possible.push_back(1);
        set<int> avoid;
        for( int i = 0 , j = 0 ; i < n ; i++ ) {
            int cnt = 0;
            while(j+cnt < m && cnt < capacity && passengers[j+cnt] <= buses[i])
                cnt++;
            j += cnt;
            int latest = (cnt < capacity) ? buses[i] : passengers[j-1];
            while(avoid.count(latest) == 0 && all_passengers.count(latest)) {
                avoid.insert(latest);
                latest--;
            }
            if(all_passengers.count(latest) == 0)
                possible.push_back(latest);
        }
        int ans = 0;
        for( int i = 0 ; i < possible.size() ; i++ )
            ans = max(ans,possible[i]);
        return ans;
    }
};
