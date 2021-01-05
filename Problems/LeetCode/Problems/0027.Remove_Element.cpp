class Solution {
public:
    int removeElement(vector<int>& ar, int val) {
        int n = ar.size();
        int len = 0 , i = 0;
        while(i < n) {
            while(i < n && ar[i] == val)
                i++;
            if(i < n)
                ar[len++] = ar[i++];
        }
        while(n > len) {
            n--;
            ar.pop_back();
        }
        return len;
    }
};