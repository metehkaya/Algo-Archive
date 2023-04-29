class Solution {
public:
    vector<vector<char>> ar;
    bool f(int r , int c , int dr , int dc , char color , char other) {
        bool var = false;
        r += dr;
        c += dc;
        while(r >= 0 && r < 8 && c >= 0 && c < 8 && ar[r][c] == other)
            var = true , r += dr , c += dc;
        if(!var)
            return false;
        if(r < 0 || r >= 8 || c < 0 || c >= 8)
            return false;
        return (ar[r][c] == color);
    }
    bool checkMove(vector<vector<char>>& board, int r, int c, char color) {
        ar = board;
        char other = (color == 'W') ? 'B' : 'W';
        bool ans = false;
        if(f(r,c,0,1,color,other) || f(r,c,0,-1,color,other) || f(r,c,1,0,color,other) || f(r,c,-1,0,color,other))
            ans = true;
        if(f(r,c,1,1,color,other) || f(r,c,1,-1,color,other) || f(r,c,-1,1,color,other) || f(r,c,-1,-1,color,other))
            ans = true;
        return ans;
    }
};