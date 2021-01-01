class Solution {
public:
    int sumOfDigits(vector<int>& ar) {
        int n = ar.size();
        int index = 0;
        for( int i = 1 ; i < n ; i++ )
            if(ar[i] < ar[index])
                index = i;
        int sum = 0 , num = ar[index];
        while(num) {
            int dig = num % 10;
            num /= 10;
            sum += dig;
        }
        return !(sum%2);
    }
};