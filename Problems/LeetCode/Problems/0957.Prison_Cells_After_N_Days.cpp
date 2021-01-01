class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& arr, int N) {
        vector<int> values(256,-1);
        vector<int> revVal(256,-1);
        int sum = 0;
        for( int i = 0 ; i < 8 ; i++ )
            sum |= (arr[i] << i);
        values[0] = sum;
        revVal[sum] = 0;
        vector<int> vNew = arr;
        int head=-1,loopLen=-1;
        for( int k = 1 ; k <= 256 ; k++ ) {
            vector<int> vOld = vNew;
            vNew[0] = vNew[7] = 0;
            for( int i = 1 ; i <= 6 ; i++ )
                vNew[i] = vOld[i-1] == vOld[i+1];
            sum = 0;
            for( int i = 0 ; i < 8 ; i++ )
                sum |= (vNew[i] << i);
            if(revVal[sum] != -1) {
                head = revVal[sum];
                loopLen = k - revVal[sum];
                break;
            }
            values[k] = sum;
            revVal[sum] = k;
        }
        int ansVal;
        if( N < head )
            ansVal = values[N];
        else
            ansVal = values[head+((N-head)%loopLen)];
        vector<int> ans(8,0);
        for( int i = 0 ; i < 8 ; i++ )
            if( ansVal & (1<<i) )
                ans[i] = 1;
        return ans;
    }
};