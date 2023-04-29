class Solution {
public:
    bool isBoomerang(vector<vector<int>>& ar) {
        sort(ar.begin(),ar.end());
        if(ar[0] == ar[1] or ar[0] == ar[2] or ar[1] == ar[2])
            return false;
        return (ar[1][1]-ar[0][1])*(ar[2][0]-ar[0][0]) != (ar[2][1]-ar[0][1])*(ar[1][0]-ar[0][0]);
    }
};