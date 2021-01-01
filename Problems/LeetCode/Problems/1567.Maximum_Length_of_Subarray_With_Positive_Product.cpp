class Solution {
public:
    int getMaxLen(vector<int>& ar) {
        int n = ar.size() , ans = 0;
        int idxPos = 0 , idxNeg = -1;
        bool isPos = true;
        for( int i = 0 ; i < n ; i++ ) {
            if(ar[i] == 0) {
                idxPos = i+1;
                idxNeg = -1;
                isPos = true;
            }
            else if(ar[i] > 0) {
                if(isPos && idxPos != -1)
                    ans = max(ans,i-idxPos+1);
                else if(!isPos && idxNeg != -1)
                    ans = max(ans,i-idxNeg+1);
            }
            else {
                isPos = !isPos;
                if(!isPos && idxNeg == -1)
                    idxNeg = i+1;
                if(isPos && idxPos != -1)
                    ans = max(ans,i-idxPos+1);
                else if(!isPos && idxNeg != -1)
                    ans = max(ans,i-idxNeg+1);
            }
        }
        return ans;
    }
};