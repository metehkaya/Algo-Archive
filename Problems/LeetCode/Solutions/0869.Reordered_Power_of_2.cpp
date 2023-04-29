class Solution {
public:
    bool check(int n) {
        for( int i = 0 ; i < 30 ; i++ )
            if((1<<i) == n)
                return true;
        return false;
    }
    bool reorderedPowerOf2(int n) {
        vector<int> v;
        while(n) {
            v.push_back(n%10);
            n /= 10;
        }
        int sz = v.size();
        sort(v.begin(),v.end());
        do {
            int val = 0;
            if(v[0] > 0) {
                n = 0;
                for( int i = 0 ; i < sz ; i++ )
                    n = 10*n + v[i];
                if(check(n))
                    return true;
            }
        }while(next_permutation(v.begin(),v.end()));
        return false;
    }
};