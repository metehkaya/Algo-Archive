class Solution {
public:
    bool hasTrailingZeros(vector<int>& v) {
        int n = v.size() , cnt = 0;
        for(int x : v)
            if(x % 2 == 0)
                cnt++;
        return cnt >= 2;
    }
};
