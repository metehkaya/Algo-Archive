class Solution {
public:
    bool canReach(string s, int minj, int maxj) {
        int n = s.length();
        priority_queue<int> heap;
        vector<bool> ans(n,false);
        ans[n-1] = (s[n-1] == '0');
        for( int i = n-2 ; i >= 0 ; i-- ) {
            if(i+minj < n && ans[i+minj])
                heap.push(i+minj);
            while(!heap.empty() && heap.top() > i+maxj)
                heap.pop();
            if(s[i] == '0' && !heap.empty())
                ans[i] = true;
        }
        return ans[0];
    }
};