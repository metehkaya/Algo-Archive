class Solution {
public:
    vector<int> constructRectangle(int n) {
        int w = sqrt(n);
        while(n%w)
            w--;
        vector<int> ans;
        ans.push_back(n/w);
        ans.push_back(w);
        return ans;
    }
};