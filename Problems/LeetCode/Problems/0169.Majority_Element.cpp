class Solution {
public:
    int majorityElement(vector<int>& ar) {
        int n = ar.size();
        int val = ar[0] , cnt = 1;
        for( int i = 1 ; i < n ; i++ ) {
            if(val == ar[i])
                cnt++;
            else if(cnt)
                cnt--;
            else
                val = ar[i] , cnt = 1;
        }
        return val;
    }
};