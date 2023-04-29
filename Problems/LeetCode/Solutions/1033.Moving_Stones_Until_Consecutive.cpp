class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        int ar[3] = {a,b,c};
        sort(ar,ar+3);
        vector<int> ans(2,0);
        if(ar[2] == ar[0]+2)
            return ans;
        int diff1 = ar[1]-ar[0];
        int diff2 = ar[2]-ar[1];
        if(min(diff1,diff2) <= 2)
            ans[0] = 1;
        else
            ans[0] = 2;
        ans[1] = diff1 + diff2 - 2;
        return ans;
    }
};