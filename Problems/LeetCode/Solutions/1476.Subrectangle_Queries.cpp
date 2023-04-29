struct update {
    int r1,c1,r2,c2,val;
    update(int _r1 , int _c1 , int _r2, int _c2 , int _val) {
        r1 = _r1 , c1 = _c1;
        r2 = _r2 , c2 = _c2;
        val = _val;
    }
};

class SubrectangleQueries {
public:
    int n,m,k;
    vector<update> v;
    vector<vector<int>> ar;
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        k = 0;
        ar = rectangle;
        n = ar.size();
        m = ar[0].size();
    }
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        k++;
        update u(row1,col1,row2,col2,newValue);
        v.push_back(u);
    }
    int getValue(int r, int c) {
        for( int i = k-1 ; i >= 0 ; i-- )
            if(v[i].r1 <= r && r <= v[i].r2 && v[i].c1 <= c && c <= v[i].c2)
                return v[i].val;
        return ar[r][c];
    }
};