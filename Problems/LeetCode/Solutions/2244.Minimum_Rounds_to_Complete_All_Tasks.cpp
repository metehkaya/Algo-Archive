class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int> cnt;
        for(int x : tasks)
            cnt[x]++;
        int ans = 0;
        for(auto it : cnt) {
            int x = it.second;
            if(x == 1)
                return -1;
            ans += (x+2)/3;
        }
        return ans;
    }
};
