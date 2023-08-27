class Solution {
public:
    long long minimumPossibleSum(int n, int k) {
        set<int> s;
        int num = 0;
        long long ans = 0;
        while(n > 0) {
            num++;
            if(s.find(num) != s.end())
                continue;
            n--;
            ans += num;
            s.insert(k-num);
        }
        return ans;
    }
};
