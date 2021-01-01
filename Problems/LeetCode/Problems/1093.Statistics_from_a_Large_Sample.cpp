class Solution {
public:
    double f(vector<int>& count, int sum) {
        int total = 0;
        for( int i = 0 ; i < 256 ; i++ ) {
            total += count[i];
            if(total >= sum)
                return i;
        }
        return -1;
    }
    vector<double> sampleStats(vector<int>& count) {
        vector<double> ans(5);
        for( int i = 0 ; i < 256 ; i++ )
            if(count[i] > 0) {
                ans[0] = i;
                break;
            }
        for( int i = 255 ; i >= 0 ; i-- )
            if(count[i] > 0) {
                ans[1] = i;
                break;
            }
        int sum = 0;
        for( int i = 0 ; i < 256 ; i++ )
            sum += count[i];
        ans[2] = 0;
        for( int i = 0 ; i < 256 ; i++ )
            ans[2] += (double) i * count[i] / sum;
        ans[3] = f(count, (sum+1)/2) + f(count, (sum+2)/2);
        ans[3] /= 2.0;
        ans[4] = 0;
        for( int i = 1 ; i < 256 ; i++ )
            if(count[i] > count[ans[4]])
                ans[4] = i;
        return ans;
    }
};