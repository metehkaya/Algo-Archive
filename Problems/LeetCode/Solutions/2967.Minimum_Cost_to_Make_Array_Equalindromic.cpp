class Solution {
public:
    bool check(int x) {
        string s = to_string(x);
        string t = s;
        reverse(t.begin(),t.end());
        return s == t;
    }
    long long get_cost(vector<int>& nums , long long x) {
        long long sum = 0;
        for(int num : nums)
            sum += abs(x-num);
        return sum;
    }
    long long minimumCost(vector<int>& v) {
        int n = v.size();
        sort(v.begin(),v.end());
        int m1 = v[n/2] , m2 = v[n/2];
        while(!check(m1))
            m1--;
        while(!check(m2))
            m2++;
        long long cost1 = get_cost(v,m1);
        long long cost2 = get_cost(v,m2);
        return min(cost1,cost2);
    }
};