struct pack {
    int x,type,id;
};

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& ar) {
        int n = ar.size();
        vector<pack> v;
        vector<int> ans(n,-1);
        for( int i = 0 ; i < n ; i++ ) {
            pack p1,p2;
            p1.x = ar[i][0];
            p1.type = 1;
            p1.id = i;
            v.push_back(p1);
            p2.x = ar[i][1];
            p2.type = 0;
            p2.id = i;
            v.push_back(p2);
        }
        sort(v.begin() , v.end() , [](pack a , pack b) {
            if(a.x != b.x)
                return a.x < b.x;
            return a.type < b.type;
        });
        vector<int> open;
        for( int i = 0 ; i < 2*n ; i++ )
            if(v[i].type == 1) {
                for( int j = 0 ; j < open.size() ; j++ )
                    ans[open[j]] = v[i].id;
                open.clear();
            }
            else
                open.push_back(v[i].id);
        return ans;
    }
};