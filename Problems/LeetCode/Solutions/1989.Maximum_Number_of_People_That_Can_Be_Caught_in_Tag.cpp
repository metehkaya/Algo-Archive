class Solution {
public:
    int catchMaximumAmountofPeople(vector<int>& v, int d) {
        int n = v.size() , ans = 0;
        queue<int> q[2];
        for( int i = 0 ; i < n ; i++ ) {
            for( int k = 0 ; k < 2 ; k++ )
                while(!q[k].empty() and i-q[k].front() > d)
                    q[k].pop();
            int x = v[i];
            if(!q[!x].empty()) {
                ans++;
                q[!x].pop();
            }
            else
                q[x].push(i);
        }
        return ans;
    }
};
