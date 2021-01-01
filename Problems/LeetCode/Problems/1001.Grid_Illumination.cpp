typedef pair<int,int> pi;

class Solution {
public:
    void eraseNum(multiset<int>& s , int num) {
        multiset<int>::iterator it = s.find(num);
        if(it != s.end())
            s.erase(it);
    }
    vector<int> gridIllumination(int N, vector<vector<int>>& l, vector<vector<int>>& q) {
        int n = l.size();
        int m = q.size();
        multiset<pi> sl;
        multiset<int> sx,sy,sxpy,sxmy;
        for( int i = 0 ; i < n ; i++ ) {
            int x = l[i][0];
            int y = l[i][1];
            sx.insert(x);
            sy.insert(y);
            sxpy.insert(x+y);
            sxmy.insert(x-y);
            sl.insert(pi(x,y));
        }
        vector<int> ans;
        for( int i = 0 ; i < m ; i++ ) {
            int x = q[i][0];
            int y = q[i][1];
            if(sx.find(x) != sx.end() or sy.find(y) != sy.end() or sxpy.find(x+y) != sxpy.end() or sxmy.find(x-y) != sxmy.end())
                ans.push_back(1);
            else
                ans.push_back(0);
            for( int a = -1 ; a <= 1 ; a++ )
                for( int b = -1 ; b <= 1 ; b++ )
                    if(sl.find(pi(x+a,y+b)) != sl.end()) {
                        int r = x+a , c = y+b;
                        eraseNum(sx,r);
                        eraseNum(sy,c);
                        eraseNum(sxpy,r+c);
                        eraseNum(sxmy,r-c);
                        sl.erase(pi(r,c));
                    }
        }
        return ans;
    }
};