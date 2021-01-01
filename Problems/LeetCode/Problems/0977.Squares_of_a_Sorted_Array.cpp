class Solution {
public:
    vector<int> sortedSquares(vector<int>& ar) {
        int n = ar.size();
        int plus = 0;
        int minus = 0;
        while(plus < n && ar[plus] <= 0)
            plus++;
        while(minus < n && ar[minus] < 0)
            minus++;
        vector<int> ans;
        for( int i = 0 ; i < plus-minus ; i++ )
            ans.push_back(0);
        while(plus < n && minus > 0) {
            int vPlus = ar[plus];
            int vMinus = ar[minus-1];
            if(vPlus < -vMinus) {
                plus++;
                ans.push_back(vPlus*vPlus);
            }
            else {
                minus--;
                ans.push_back(vMinus*vMinus);
            }
        }
        while(plus < n) {
            ans.push_back(ar[plus]*ar[plus]);
            plus++;
        }
        while(minus > 0) {
            ans.push_back(ar[minus-1]*ar[minus-1]);
            minus--;
        }
        return ans;
    }
};