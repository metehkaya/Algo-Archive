class Solution {
public:
    int gcd(int x , int y) {
        if(!y)
            return x;
        return gcd(y,x%y);
    }
    bool hasGroupsSizeX(vector<int>& ar) {
        int n = ar.size() , ans = -1;
        sort(ar.begin(),ar.end());
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            while(j < n && ar[i] == ar[j])
                j++;
            int diff = j-i;
            if(ans == -1)
                ans = diff;
            else
                ans = gcd(ans,diff);
        }
        return ans >= 2;
    }
};