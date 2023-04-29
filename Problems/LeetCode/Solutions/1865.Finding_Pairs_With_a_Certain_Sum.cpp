class FindSumPairs {
public:
    int n,m;
    vector<int> a,b;
    map<int,int> cnt;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        a = nums1;
        b = nums2;
        n = a.size();
        m = b.size();
        for( int i = 0 ; i < m ; i++ )
            cnt[b[i]]++;
    }
    void add(int idx, int val) {
        cnt[b[idx]]--;
        b[idx] += val;
        cnt[b[idx]]++;
    }
    int count(int tot) {
        int ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            map<int,int>::iterator it = cnt.find(tot-a[i]);
            if(it != cnt.end())
                ans += (*it).second;
        }
        return ans;
    }
};