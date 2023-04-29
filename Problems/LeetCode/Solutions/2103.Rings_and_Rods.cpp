class Solution {
public:
    int countPoints(string rings) {
        int n = rings.length()/2;
        vector<int> bmask(10,0);
        for( int i = 0 ; i < n ; i++ ) {
            char c = rings[2*i];
            int k = rings[2*i+1]-'0';
            if(c == 'R')
                bmask[k] |= 1;
            if(c == 'G')
                bmask[k] |= 2;
            if(c == 'B')
                bmask[k] |= 4;
        }
        int ans = 0;
        for( int i = 0 ; i < 10 ; i++ )
            ans += (bmask[i] == 7);
        return ans;
    }
};
