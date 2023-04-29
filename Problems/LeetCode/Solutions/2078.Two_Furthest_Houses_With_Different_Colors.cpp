class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        for( int d = n-1 ; d > 0 ; d-- )
            for( int i = 0 ; i+d < n ; i++ )
                if(colors[i] != colors[i+d])
                    return d;
        return -1;
    }
};
