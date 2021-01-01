class Solution {
public:
    int totalFruit(vector<int>& ar) {
        int ans = 0;
        int n = ar.size();
        int c1 = 0 , c2 = 0;
        int t1 = -1 , t2 = -1;
        int i = 0 , j = 0;
        while(i < n) {
            while(j < n && (ar[j] == t1 || ar[j] == t2 || t1 == -1 || t2 == -1)) {
                if(ar[j] == t1)
                    c1++;
                else if(ar[j] == t2)
                    c2++;
                else if(t1 == -1) {
                    t1 = ar[j];
                    c1 = 1;
                }
                else {
                    t2 = ar[j];
                    c2 = 1;
                }
                j++;
            }
            ans = max(ans, c1+c2);
            if(j == n)
                break;
            while(t1 != -1 && t2 != -1) {
                if(ar[i] == t1) {
                    if(--c1 == 0)
                        t1 = -1;
                }
                else {
                    if(--c2 == 0)
                        t2 = -1;
                }
                i++;
            }
        }
        return ans;
    }
};