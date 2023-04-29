typedef vector<int> vi;

class Solution {
public:
    const int N = 10;
    vi num2digits(int num) {
        vi v(N,0);
        int curr = N-1;
        while(num) {
            int dig = num%10;
            num /= 10;
            v[curr--] = dig;
        }
        return v;
    }
    int digits2num(vi& v) {
        int val = 0;
        for( int i = 0 ; i < N ; i++ )
            val = val*10 + v[i];
        return val;
    }
    void f(int index, vi& curr, vi& l, vi& h, bool isZero, bool biggerThanLow, bool smallerThanHigh, vi& ans) {
        if(index == N) {
            ans.push_back( digits2num(curr) );
            return;
        }
        if(isZero) {
            for( int num = 0 ; num < N ; num++ ) {
                if( (biggerThanLow || num >= l[index]) && (smallerThanHigh || num <= h[index]) ) {
                    curr[index] = num;
                    f(index+1,curr,l,h,isZero&&(num==0),biggerThanLow||(num>l[index]),smallerThanHigh||(num<h[index]),ans);
                }
            }
        }
        else {
            if(curr[index-1] > 0) {
                int num = curr[index-1] - 1;
                if( (biggerThanLow || num >= l[index]) && (smallerThanHigh || num <= h[index]) ) {
                    curr[index] = num;
                    f(index+1,curr,l,h,isZero&&(num==0),biggerThanLow||(num>l[index]),smallerThanHigh||(num<h[index]),ans);
                }
            }
            if(curr[index-1] < N-1) {
                int num = curr[index-1] + 1;
                if( (biggerThanLow || num >= l[index]) && (smallerThanHigh || num <= h[index]) ) {
                    curr[index] = num;
                    f(index+1,curr,l,h,isZero&&(num==0),biggerThanLow||(num>l[index]),smallerThanHigh||(num<h[index]),ans);
                }
            }
        }
    }
    vi countSteppingNumbers(int low, int high) {
        vi l = num2digits(low);
        vi h = num2digits(high);
        vi ans;
        vi curr(N,0);
        f(0,curr,l,h,true,false,false,ans);
        return ans;
    }
};