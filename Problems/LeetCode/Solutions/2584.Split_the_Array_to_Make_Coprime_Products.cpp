class Solution {
public:
    static const int maxs = (int) 1e6+1;
    void f(int num , vector<int>& primes) {
        for( int i = 2 ; i*i <= num ; i++ )
            if(num % i == 0) {
                primes.push_back(i);
                while(num % i == 0)
                    num /= i;
            }
        if(num > 1)
            primes.push_back(num);
    }
    int findValidSplit(vector<int>& nums) {
        int n = nums.size();
        vector<int> first(maxs,-1);
        vector<int> last(maxs,-1);
        for( int i = 0 ; i < n ; i++ ) {
            int num = nums[i];
            vector<int> primes;
            f(num,primes);
            for(int prime : primes) {
                if(first[prime] == -1)
                    first[prime] = i;
                last[prime] = i;
            }
        }
        vector<int> add(maxs,0);
        for( int i = 0 ; i < maxs ; i++ )
            if(first[i] != last[i]) {
                add[first[i]]++;
                add[last[i]]--;
            }
        for( int i = 0 , sum = 0 ; i < n-1 ; i++ ) {
            sum += add[i];
            if(sum == 0)
                return i;
        }
        return -1;
    }
};
