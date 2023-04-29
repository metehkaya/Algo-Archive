typedef long long LL;

class Solution {
public:
    int minimumOperations(vector<int>& v) {
        int n = v.size() , cnt = 0;
        for( int l = 0 , r = n-1 ; l <= r ; ) {
            if(l == r) {
                cnt++;
                break;
            }
            LL sum_l = v[l++] , sum_r = v[r--];
            while(l <= r and sum_l != sum_r) {
                if(sum_l < sum_r)
                    sum_l += v[l++];
                else
                    sum_r += v[r--];
            }
            if(sum_l == sum_r)
                cnt += 2;
            else {
                cnt++;
                break;
            }
        }
        return n-cnt;
    }
};
