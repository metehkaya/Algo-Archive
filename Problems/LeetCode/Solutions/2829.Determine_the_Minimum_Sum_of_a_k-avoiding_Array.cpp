class Solution {
public:
    int minimumSum(int n, int k) {
        set<int> s;
        int num = 0 , ans = 0;
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