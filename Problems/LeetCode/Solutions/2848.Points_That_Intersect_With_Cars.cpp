class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        set<int> points;
        for(auto v : nums)
            for( int i = v[0] ; i <= v[1] ; i++ )
                points.insert(i);
        return (int) points.size();
    }
};
