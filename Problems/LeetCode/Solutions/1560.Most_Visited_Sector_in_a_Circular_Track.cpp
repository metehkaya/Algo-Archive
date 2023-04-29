class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& ar) {
        vector<int> ans;
        int m = ar.size();
        int x = ar[0] , y = ar[m-1];
        ans.push_back(x);
        while(x != y) {
            if(x < n)
                x++;
            else
                x = 1;
            ans.push_back(x);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};