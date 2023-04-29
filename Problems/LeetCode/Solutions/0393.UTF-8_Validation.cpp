class Solution {
public:
    bool validUtf8(vector<int>& ar) {
        int n = ar.size() , idx = 0;
        while(idx < n) {
            if(ar[idx] < 128)
                idx++;
            else if(ar[idx] >= 192 && ar[idx] < 224 && idx+2 <= n) {
                if(ar[idx+1] < 128 || ar[idx+1] >= 192)
                    return false;
                idx += 2;
            }
            else if(ar[idx] >= 224 && ar[idx] < 240 && idx+3 <= n) {
                if(ar[idx+1] < 128 || ar[idx+1] >= 192)
                    return false;
                if(ar[idx+2] < 128 || ar[idx+2] >= 192)
                    return false;
                idx += 3;
            }
            else if(ar[idx] >= 240 && ar[idx] < 248 && idx+4 <= n) {
                if(ar[idx+1] < 128 || ar[idx+1] >= 192)
                    return false;
                if(ar[idx+2] < 128 || ar[idx+2] >= 192)
                    return false;
                if(ar[idx+3] < 128 || ar[idx+3] >= 192)
                    return false;
                idx += 4;
            }
            else
                return false;
        }
        return true;
    }
};
