class Solution {
public:
    int removeDuplicates(vector<int>& ar) {
        int n = ar.size();
        int r = n-1;
        while(r >= 0) {
            int l = r;
            while(l >= 0 && ar[l] == ar[r])
                l--;
            ar.erase(ar.begin()+l+1, ar.begin()+r);
            r = l;
        }
        return ar.size();
    }
};