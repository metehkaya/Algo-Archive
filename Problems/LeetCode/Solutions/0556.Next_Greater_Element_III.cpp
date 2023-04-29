class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> digs;
        int N = n;
        while(N) {
            digs.push_back(N%10);
            N /= 10;
        }
        int nd = digs.size();
        sort(digs.begin(),digs.end());
        do {
            long long num = 0;
            for( int i = 0 ; i < nd ; i++ )
                num = 10*num + digs[i];
            if(num > n) {
                if(num > INT_MAX)
                    return -1;
                return (int)num;
            }
        }while(next_permutation(digs.begin(),digs.end()));
        return -1;
    }
};