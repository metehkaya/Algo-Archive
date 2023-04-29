typedef long long LL;

class Solution {
public:
    bool isArmstrong(int n) {
        vector<int> v;
        int temp = n;
        while(n) {
            int dig = n%10;
            v.push_back(dig);
            n /= 10;
        }
        int k = v.size();
        int sum = 0;
        for( int i = 0 ; i < k ; i++ ) {
            int num = 1;
            for( int j = 0 ; j < k ; j++ )
                num *= v[i];
            sum += num;
        }
        return temp == sum;
    }
};