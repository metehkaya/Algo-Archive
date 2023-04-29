bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long l=1,r=n,ans=n;
        while(l <= r) {
            long long mid = (l+r)>>1;
            if(isBadVersion(mid))
                ans=mid,r=mid-1;
            else
                l=mid+1;
        }
        return (int)ans;
    }
};