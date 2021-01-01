class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<int> people[n+1];
        for( int i = 0 ; i < n ; i++ )
            people[groupSizes[i]].push_back(i);
        vector<vector<int>> ans;
        for( int i = 1 ; i <= n ; i++ )
            if( people[i].size() ) {
                int sz = people[i].size();
                for( int j = 0 ; j < sz ; j += i ) {
                    vector<int> v;
                    for( int k = j ; k < j+i ; k++ )
                        v.push_back(people[i][k]);
                    ans.push_back(v);
                }
            }
        return ans;
    }
};