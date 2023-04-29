class Solution {
public:
    int maximumCount(vector<int>& v) {
        int p = 0 , n = 0;
        for(int x : v)
            if(x > 0)
                p++;
            else if(x < 0)
                n++;
        return max(p,n);
    }
};
