class Solution {
public:
    int ans;
    int goal;
    vector<int> v;
    vector<int> ar;
    void f(int i , int idx , int sum) {
        if(i == idx) {
            v.push_back(sum);
            return;
        }
        f(i+1,idx,sum);
        f(i+1,idx,sum+ar[i]);
    }
    void g(int i , int idx , int sum) {
        if(i == idx) {
            vector<int>::iterator it = lower_bound(v.begin(),v.end(),goal-sum);
            if(it != v.end())
                ans = min(ans,abs(goal-(sum+(*it))));
            if(it != v.begin()) {
                it--;
                ans = min(ans,abs(goal-(sum+(*it))));
            }
            return;
        }
        g(i+1,idx,sum);
        g(i+1,idx,sum+ar[i]);
    }
    int minAbsDifference(vector<int>& ar, int goal) {
        this->ar = ar;
        this->goal = goal;
        int n = ar.size();
        int n1 = min(n,20);
        f(0,n1,0);
        ans = INT_MAX;
        sort(v.begin(),v.end());
        g(n1,n,0);
        return ans;
    }
};