class Solution {
public:
    int n,m,ans;
    vector<vector<int>> requests;
    void f(int id , int score , vector<int>& cnt) {
        if(id == m) {
            bool ok = true;
            for( int i = 0 ; i < n ; i++ )
                if(cnt[i])
                    ok = false;
            if(ok)
                ans = max(ans,score);
            return;
        }
        f(id+1,score,cnt);
        cnt[requests[id][0]]++;
        cnt[requests[id][1]]--;
        f(id+1,score+1,cnt);
        cnt[requests[id][0]]--;
        cnt[requests[id][1]]++;
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        this->n = n;
        this->requests = requests;
        m = requests.size();
        vector<int> cnt(n,0);
        f(0,0,cnt);
        return ans;
    }
};
