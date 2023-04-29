class Solution {
public:
    int maxProduct(vector<int>& ar) {
        int n = ar.size() , ans = INT_MIN;
        int mult = 1 , neg = 0;
        for( int i = 0 ; i < n ; i++ ) {
            if(!ar[i]) {
                ans = max(ans,0);
                neg = 0;
                mult = 1;
            }
            else {
                mult *= ar[i];
                ans = max(ans,mult);
                if(mult < 0 && neg)
                    ans = max(ans,mult/neg);
                if(!neg && ar[i] < 0)
                    neg = mult;
            }
        }
        return ans;
    }
};