class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector< pair<int,int> > ar;
        vector<int> minCandies(n,1);
        for( int i = 0 ; i < n ; i++ )
            ar.push_back( make_pair( ratings[i] , i ) );
        sort( ar.begin() , ar.end() );
        int ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            int index = ar[i].second;
            int candies = minCandies[index];
            ans += candies;
            if(index > 0 && ratings[index-1] > ratings[index])
                minCandies[index-1] = max( minCandies[index-1] , candies+1 );
            if(index < n-1 && ratings[index+1] > ratings[index])
                minCandies[index+1] = max( minCandies[index+1] , candies+1 );
        }
        return ans;
    }
};