#define fi first
#define se second
#define pb push_back
typedef pair<int,int> pi;

class Solution {
public:
    vector<pi> v;
    int row[9],col[9],box[9];
    bool check(int val , int k) {
        return (val >> k) & 1;
    }
    bool f(vector<vector<char>>& ar, int idx) {
        if(idx == v.size())
            return true;
        int r = v[idx].fi , c = v[idx].se;
        int b = 3*(r/3) + c/3;
        for( int i = 0 ; i < 9 ; i++ ) {
            if(check(row[r],i) || check(col[c],i) || check(box[b],i))
                continue;
            ar[r][c] = '1'+i;
            row[r] ^= (1<<i);
            col[c] ^= (1<<i);
            box[b] ^= (1<<i);
            if(f(ar,idx+1))
                return true;
            row[r] ^= (1<<i);
            col[c] ^= (1<<i);
            box[b] ^= (1<<i);
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& ar) {
        for( int i = 0 ; i < 9 ; i++ )
            for( int j = 0 ; j < 9 ; j++ ) {
                if(ar[i][j] == '.')
                    v.pb(pi(i,j));
                else {
                    int val = ar[i][j]-'1';
                    int b = 3*(i/3) + j/3;
                    row[i] |= (1<<val);
                    col[j] |= (1<<val);
                    box[b] |= (1<<val);
                }
            }
        f(ar,0);
    }
};