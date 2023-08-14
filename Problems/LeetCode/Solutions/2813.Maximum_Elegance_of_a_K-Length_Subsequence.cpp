class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        int n = items.size();
        long long sum = 0;
        set<int> ids;
        stack<int> st;
        sort(items.begin(), items.end());
        for( int i = n-1 ; i >= n-k ; i-- ) {
            sum += items[i][0];
            if(ids.count(items[i][1]))
                st.push(items[i][0]);
            else
                ids.insert(items[i][1]);
        }
        int diff = ids.size();
        long long ans = sum + (long long) diff * diff;
        for( int i = n-k-1 ; i >= 0 ; i-- )
            if(ids.count(items[i][1]) == 0 and !st.empty()) {
                sum -= st.top();
                st.pop();
                sum += items[i][0];
                diff++;
                ids.insert(items[i][1]);
                long long temp = sum + (long long) diff * diff;
                ans = max(ans,temp);
            }
        return ans;
    }
};
