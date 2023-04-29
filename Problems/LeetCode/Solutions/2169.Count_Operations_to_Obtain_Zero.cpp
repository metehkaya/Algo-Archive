class Solution {
public:
    int countOperations(int a, int b) {
        int ans = 0;
        if(a > b)
            swap(a,b);
        while(a) {
            b -= a;
            if(a > b)
                swap(a,b);
            ans++;
        }
        return ans;
    }
};
