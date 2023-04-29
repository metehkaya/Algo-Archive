class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int m = A.size();
        int n = B.size();
        if(m > n) {
            swap(A,B);
            swap(n,m);
        }
        int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
        while(iMin <= iMax) {
            int i = (iMin + iMax) / 2;
            int j = halfLen - i;
            if(i < iMax && B[j-1] > A[i])
                iMin = i + 1;
            else if(i > iMin && A[i-1] > B[j])
                iMax = i - 1;
            else {
                int maxLeft = 0;
                if(i == 0)
                    maxLeft = B[j-1];
                else if(j == 0)
                    maxLeft = A[i-1];
                else
                    maxLeft = max(A[i-1], B[j-1]);
                if( (m + n) % 2 == 1 )
                    return maxLeft;
                int minRight = 0;
                if(i == m)
                    minRight = B[j];
                else if(j == n)
                    minRight = A[i];
                else
                    minRight = min(B[j], A[i]);

                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0.0;
    }
};