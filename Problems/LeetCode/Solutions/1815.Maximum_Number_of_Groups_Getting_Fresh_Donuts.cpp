class Solution {
public:
    int n,b,mx;
    vector<int> mults;
    map<int,int> dp;
    map<int,int>::iterator it;
    int conv(vector<int>& cnt) {
        int id = 0;
        for( int i = 0 ; i < b ; i++ )
            id += cnt[i] * mults[i];
        return id;
    }
    int f(vector<int>& cnt , int n , int sum) {
        if(n == 0)
            return 0;
        int id = conv(cnt);
        it = dp.find(id);
        if(it != dp.end())
            return it->second;
        int add = !sum , res = 0;
        for( int i = 0 ; i < b ; i++ )
            if(cnt[i]) {
                cnt[i]--;
                int sum2 = (sum+i)%b;
                res = max(res,f(cnt,n-1,sum2));
                cnt[i]++;
            }
        return dp[id] = res+add;
    }
    int maxHappyGroups(int batchSize, vector<int>& groups) {
        b = batchSize;
        n = groups.size();
        vector<int> cnt(b,0);
        for( int i = 0 ; i < n ; i++ ) {
            int rem = groups[i] % b;
            cnt[rem]++;
        }
        mults.push_back(1);
        for( int i = 0 ; i < b-1 ; i++ )
            mults.push_back(mults[i]*(cnt[i]+1));
        return f(cnt,n,0);
    }
};