class Solution {
public:
    bool isOneBitCharacter(vector<int>& ar) {
        int n = ar.size() , last = -1 , idx = 0;
        while(idx < n) {
            last = ar[idx];
            if(last == 0)
                idx += 1;
            else
                idx += 2;
        }
        return last == 0;
    }
};