class Solution {
public:
    static const int maxp = 320;
    static const int maxn = 100000;
    static const int maxs = 100001;
    int dad[maxn];
    int lvl[maxn];
    int first_id[maxs];
    int find_dad(int x) {
        if(dad[x] == -1)
            return x;
        return dad[x] = find_dad(dad[x]);
    }
    void merge(int x , int y) {
        x = find_dad(x);
        y = find_dad(y);
        if(x == y)
            return;
        if(lvl[x] > lvl[y])
            swap(x,y);
        dad[x] = y;
        if(lvl[x] == lvl[y])
            lvl[y]++;
    }
    void deal(int x , int idx) {
        if(first_id[x] == -1)
            first_id[x] = idx;
        else
            merge(idx,first_id[x]);
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        memset(dad,-1,sizeof(dad));
        memset(first_id,-1,sizeof(first_id));
        int n = nums.size();
        for( int i = 0 ; i < n ; i++ ) {
            int x = nums[i];
            for( int p = 2 ; p < maxp ; p++ )
                if(x % p == 0) {
                    deal(p,i);
                    while(x%p == 0)
                        x /= p;
                }
            if(x > 1)
                deal(x,i);
        }
        int cnt = 0;
        for( int i = 0 ; i < n ; i++ )
            cnt += (dad[i] == -1);
        return (cnt == 1);
    }
};
