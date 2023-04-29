class Solution {
public:
    int n,sum,g,k;
    vector<int> ar;
    bool mark[65536];
    bool f(int bmask , int sum , int cnt) {
        if(cnt == k)
            return true;
        if(mark[bmask])
            return false;
        mark[bmask] = true;
        for( int i = 0 ; i < n ; i++ )
            if((bmask & (1<<i)) == 0) {
                int newsum = sum + ar[i];
                int newbmask = (bmask | (1<<i));
                int newcnt = cnt;
                if(newsum == g)
                    newcnt = cnt+1 , newsum = 0;
                if(newsum < g)
                    if(f(newbmask,newsum,newcnt))
                        return true;
            }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        this->k = k;
        ar = nums;
        n = ar.size();
        for( int i = 0 ; i < n ; i++ )
            sum += ar[i];
        if(sum % k)
            return false;
        g = sum / k;
        return f(0,0,0);
    }
};