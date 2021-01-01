typedef vector<int> vi;
typedef set<vi> svi;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& ar, int k) {
        svi s;
        int n = ar.size();
        int m = ar[0].size();
        vector<int> init(n+1,0);
        for( int i = 0 ; i < n ; i++ )
            init[0] += ar[i][0];
        s.insert(init);
        while(--k) {
            vector<int> v = *(s.begin());
            s.erase(s.begin());
            for( int i = 0 ; i < n ; i++ )
                if( v[i+1] + 1 < m ) {
                    vector<int> temp = v;
                    temp[0] += ar[i][v[i+1]+1] - ar[i][v[i+1]];
                    temp[i+1]++;
                    s.insert(temp);
                }
        }
        vector<int> res = *(s.begin());
        return res[0];
    }
};