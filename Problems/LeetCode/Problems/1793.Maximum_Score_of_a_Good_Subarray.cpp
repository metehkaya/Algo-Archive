#define fi first
#define se second
typedef pair<int,int> pi;

class Solution {
public:
    vector<int> cnt,dad;
    int findPar(int u) {
        if(dad[u] == u)
            return u;
        return dad[u] = findPar(dad[u]);
    }
    void merge(int u , int v) {
        if(dad[u] == -1 || dad[v] == -1)
            return;
        u = findPar(u);
        v = findPar(v);
        if(u != v) {
            if(cnt[u] > cnt[v])
                swap(u,v);
            dad[u] = v;
            cnt[v] += cnt[u];
        }
    }
    int maximumScore(vector<int>& nums, int k) {
        vector<pi> ar;
        int n = nums.size();
        for( int i = 0 ; i < n ; i++ ) {
            cnt.push_back(0);
            dad.push_back(-1);
            ar.push_back(pi(nums[i],i));
        }
        int ans = 0;
        sort(ar.begin(),ar.end());
        for( int i = n-1 , j ; i >= 0 ; i = j ) {
            j = i;
            while(j >= 0 && ar[i].fi == ar[j].fi) {
                int idx = ar[j].se;
                cnt[idx] = 1;
                dad[idx] = idx;
                if(idx > 0)
                    merge(idx,idx-1);
                if(idx < n-1)
                    merge(idx,idx+1);
                j--;
            }
            if(cnt[k]) {
                int u = findPar(k);
                ans = max(ans,cnt[u]*ar[i].fi);
            }
        }
        return ans;
    }
};