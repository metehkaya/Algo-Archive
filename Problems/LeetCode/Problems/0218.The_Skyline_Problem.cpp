#define fi first
#define se second
typedef pair<int,int> pi;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& ar) {
        vector<pi> v;
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ ) {
            v.push_back(pi(ar[i][0],ar[i][2]));
            v.push_back(pi(ar[i][1],-ar[i][2]));
        }
        sort(v.begin(),v.end());
        multiset<int> s;
        s.insert(0);
        vector<vector<int>> ans;
        for( int i = 0 , j = 0 , h = 0 ; i < 2*n ; i = j ) {
            while(j < 2*n && v[i].fi == v[j].fi)
                j++;
            for( int k = i ; k < j ; k++ ) {
                int val = v[k].se;
                if(val > 0)
                    s.insert(val);
                else if(val < 0) {
                    auto it = s.find(-val);
                    s.erase(it);
                }
            }
            int nextH = *(s.rbegin());
            if(h != nextH) {
                h = nextH;
                vector<int> add(2);
                add[0] = v[i].fi;
                add[1] = h;
                ans.push_back(add);
            }
        }
        return ans;
    }
};