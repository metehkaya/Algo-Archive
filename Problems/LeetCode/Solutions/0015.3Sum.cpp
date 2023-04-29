typedef vector<int> vi;
typedef vector<vi> vii;

class Solution {
public:
    vii threeSum(vi& ar) {
        vii ans;
        vi add(3);
        int n = ar.size();
        sort(ar.begin(),ar.end());
        for( int i = 0 ; i < n ; i++ )
            if(!i or ar[i] != ar[i-1]) {
                int k = n-1;
                for( int j = i+1 ; j < n ; j++ )
                    if(j == i+1 or ar[j] != ar[j-1]) {
                        while(k>j+1 and ar[i]+ar[j]+ar[k] > 0)
                            k--;
                        if(k>j and ar[i]+ar[j]+ar[k] == 0) {
                            add[0] = ar[i];
                            add[1] = ar[j];
                            add[2] = ar[k];
                            ans.push_back(add);
                        }
                    }
            }
        return ans;
    }
};