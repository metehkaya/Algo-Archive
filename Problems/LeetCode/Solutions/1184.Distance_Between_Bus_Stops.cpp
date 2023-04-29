class Solution {
public:
    int distanceBetweenBusStops(vector<int>& dist, int s, int e) {
        int d1 = 0 , d2 = 0;
        int n = dist.size();
        for( int i = s ; i != e && i != e+n ; i++ )
            d1 += dist[i%n];
        for( int i = s+n ; i != e && i != e+n ; i-- )
            d2 += dist[(i-1)%n];
        return min(d1,d2);
    }
};