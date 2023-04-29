class Solution {
public:
    bool check(int num) {
        int temp = num;
        while(temp) {
            int x = temp%10;
            if(!x || num%x)
                return false;
            temp /= 10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for( int i = left ; i <= right ; i++ )
            if(check(i))
                ans.push_back(i);
        return ans;
    }
};