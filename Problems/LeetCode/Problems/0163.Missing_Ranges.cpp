class Solution {
public:
    string toString(int number) {
        if(number == 0)
            return "0";
        if(number == -2147483648)
            return "-2147483648";
        string res = "";
        bool sign = false;
        if(number < 0) {
            sign = true;
            number *= -1;
        }
        while(number) {
            char c = (char)('0' + (number%10));
            number /= 10;
            res.push_back(c);
        }
        if(sign)
            res.push_back('-');
        reverse(res.begin(), res.end());
        return res;
    }
    pair<int,int> findIntersection(int s, int e, int l, int r) {
        return make_pair( max(s,l) , min(e,r) );
    }
    void dealRange(int s, int e, int l, int r, vector<string>& ans) {
        pair<int,int> p = findIntersection(s,e,l,r);
        if( p.first <= p.second ) {
            string res = toString(p.first);
            if( p.first < p.second )
                res += "->" + toString(p.second);
            ans.push_back(res);
        }
    }
    vector<string> findMissingRanges(vector<int>& ar, int lower, int upper) {
        int n = ar.size();
        vector<string> ans;
        if(n == 0) {
            string res = toString(lower);
            if(lower < upper)
                res += "->" + toString(upper);
            ans.push_back(res);
        }
        else {
            if(ar[0] != INT_MIN)
                dealRange(INT_MIN, ar[0]-1, lower, upper, ans);
            for( int i = 0 ; i < n-1 ; i++ )
                if( ar[i] != ar[i+1] )
                    dealRange(ar[i]+1, ar[i+1]-1, lower, upper, ans);
            if(ar[n-1] != INT_MAX)
                dealRange(ar[n-1]+1, INT_MAX, lower, upper, ans);
        }
        return ans;
    }
};
