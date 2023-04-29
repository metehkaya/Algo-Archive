class Solution {
public:
    void f(int id , vector<int>& v) {
        int x = 1 , lvl = 0;
        while(id >= 2*x)
            x *= 2 , lvl++;
        x = id-x;
        for( int i = lvl-1 ; i >= 0 ; i-- )
            if(x & (1<<i))
                v.push_back(1);
            else
                v.push_back(0);
    }
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& q) {
        vector<int> ans;
        int m = q.size();
        for(auto v : q) {
            int x = v[0] , y = v[1];
            vector<int> v1,v2;
            f(x,v1);
            f(y,v2);
            int sz1 = v1.size();
            int sz2 = v2.size();
            int comm = 0;
            while(comm < min(sz1,sz2) && v1[comm] == v2[comm])
                comm++;
            ans.push_back(sz1+sz2-2*comm+1);
        }
        return ans;
    }
};
