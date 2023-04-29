class Solution {
public:
    int f(priority_queue<int>& q1 , priority_queue<int>& q2 , int sum) {
        int cnt = 0;
        while(sum > 0 && !q1.empty() && !q2.empty()) {
            cnt++;
            int x = q1.top();
            int y = q2.top();
            if(x >= y) {
                sum -= x;
                q1.pop();
            }
            else {
                sum -= y;
                q2.pop();
            }
        }
        while(sum > 0 && !q1.empty()) {
            cnt++;
            int x = q1.top();
            q1.pop();
            sum -= x;
        }
        while(sum > 0 && !q2.empty()) {
            cnt++;
            int x = q2.top();
            q2.pop();
            sum -= x;
        }
        return cnt;
    }
    int minOperations(vector<int>& ar1, vector<int>& ar2) {
        int n = ar1.size();
        int m = ar2.size();
        if(n > 6*m || m > 6*n)
            return -1;
        int sum = 0;
        priority_queue<int> q1,q2,q3,q4;
        for( int i = 0 ; i < n ; i++ ) {
            sum += ar1[i];
            if(ar1[i] > 1)
                q1.push(ar1[i]-1);
            if(ar1[i] < 6)
                q2.push(6-ar1[i]);
        }
        for( int i = 0 ; i < m ; i++ ) {
            sum -= ar2[i];
            if(ar2[i] > 1)
                q3.push(ar2[i]-1);
            if(ar2[i] < 6)
                q4.push(6-ar2[i]);
        }
        int ans;
        if(sum == 0)
            ans = 0;
        else if(sum > 0)
            ans = f(q1,q4,sum);
        else
            ans = f(q2,q3,-sum);
        return ans;
    }
};