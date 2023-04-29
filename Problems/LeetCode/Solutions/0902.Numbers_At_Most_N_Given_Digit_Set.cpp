class Solution {
public:
    int calcPow(int x , int y) {
        int res = 1;
        for( int i = 0 ; i < y ; i++ )
            res *= x;
        return res;
    }
    int f(int idx , int num , bool smaller , int n , vector<int>& digs , vector<int>& v) {
        if(smaller or idx == n)
            return calcPow(digs.size(),n-idx);
        int ans = 0;
        for( int i = 0 ; i < digs.size() ; i++ )
            if(digs[i] <= v[idx])
                ans += f( idx+1 , 10*num+digs[i] , smaller or (digs[i] < v[idx]) , n , digs , v );
        return ans;
    }
    int atMostNGivenDigitSet(vector<string>& s, int n) {
        vector<int> digs;
        for( int i = 0 ; i < s.size() ; i++ )
            digs.push_back(s[i][0]-'0');
        sort(digs.begin(),digs.end());
        vector<int> v;
        while(n) {
            v.push_back(n%10);
            n /= 10;
        }
        reverse(v.begin(),v.end());
        int ans = 0;
        for( int i = 1 ; i <= v.size()-1 ; i++ ) {
            int add = 1;
            for( int j = 0 ; j < i ; j++ )
                add *= digs.size();
            ans += add;
        }
        ans += f(0,0,false,v.size(),digs,v);
        return ans;
    }
};