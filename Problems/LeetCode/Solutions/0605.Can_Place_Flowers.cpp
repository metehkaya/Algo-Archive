class Solution {
public:
    bool canPlaceFlowers(vector<int>& ar, int k) {
        int n = ar.size();
        vector<int> v;
        for( int i = 0 ; i < n ; i++ )
            if(ar[i] == 1)
                v.push_back(i);
        int mx = 0;
        if(v.empty())
            mx = (n+1)/2;
        else {
            int cnt = v.size();
            mx += v[0] / 2;
            mx += (n-1 - v[cnt-1]) / 2;
            for( int i = 1 ; i < cnt ; i++ )
                if(v[i] - v[i-1] >= 4)
                    mx += (v[i] - v[i-1] - 2) / 2;
        }
        return mx >= k;
    }
};