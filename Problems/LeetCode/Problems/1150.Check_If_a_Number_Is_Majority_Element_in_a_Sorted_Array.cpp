class Solution {
public:
    bool isMajorityElement(vector<int>& ar, int target) {
        int n = ar.size() , cnt = 0;
        for( int i = 0 ; i < n ; i++ )
            if(ar[i] == target)
                cnt++;
        return cnt > n/2;
    }
};