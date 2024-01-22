class Solution {
public:
    int minimumArrayLength(vector<int>& v) {
        int n = v.size();
        sort(v.begin(),v.end());
        int f = v[0] , cnt = 0;
        for(int val : v) {
            if(val % f)
                return 1;
            else if(val == f)
                cnt++;
        }
        return (cnt+1)/2;
    }
};
