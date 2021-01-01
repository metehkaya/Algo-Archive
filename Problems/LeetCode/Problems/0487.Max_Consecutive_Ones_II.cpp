class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& ar) {
        int n = ar.size();
        if(n <= 1)
            return n;
        int ans = 1;
        int prevIdx = -1;
        int prevLen = -1;
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            while(j < n && ar[i] == ar[j])
                j++;
            if(ar[i] == 1) {
                int ones = j-i;
                ans = max(ans,min(n,ones+1));
                if(prevIdx != -1 && prevIdx+prevLen+1 == i)
                    ans = max(ans,prevLen+ones+1);
                prevIdx = i;
                prevLen = ones;
            }
        }
        return ans;
    }
};