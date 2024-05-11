class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = 0;
        for(int x : apple)
            sum += x;
        sort(capacity.begin(),capacity.end());
        int n = capacity.size() , ans = 0;
        while(sum > 0)
            sum -= capacity[n-(++ans)];
        return ans;
    }
};
