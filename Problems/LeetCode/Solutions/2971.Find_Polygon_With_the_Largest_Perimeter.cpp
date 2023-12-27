class Solution {
public:
    long long largestPerimeter(vector<int>& v) {
        int n = v.size();
        sort(v.begin(),v.end());
        long long sum = 0;
        for(int x : v)
            sum += x;
        for( int i = n-1 ; i >= 2 ; i-- ) {
            sum -= v[i];
            if(sum > v[i])
                return sum+v[i];
        }
        return -1;
    }
};
