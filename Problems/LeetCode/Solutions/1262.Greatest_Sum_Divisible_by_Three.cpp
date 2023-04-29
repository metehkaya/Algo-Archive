class Solution {
public:
    int maxSumDivThree(vector<int>& ar) {
        int n = ar.size();
        sort( ar.begin() , ar.end() );
        int sum=0,s11=-1,s12=-1,s21=-1,s22=-1;
        for( int i = 0 ; i < n ; i++ ) {
            sum += ar[i];
            if( s11 == -1 && ar[i] % 3 == 1 )
                s11 = ar[i];
            else if( s12 == -1 && ar[i] % 3 == 1 )
                s12 = ar[i];
            else if( s21 == -1 && ar[i] % 3 == 2 )
                s21 = ar[i];
            else if( s22 == -1 && ar[i] % 3 == 2 )
                s22 = ar[i];
        }
        int ans = 0;
        if(sum % 3 == 1) {
            if(s11 != -1)
                ans = max(ans,sum-s11);
            if(s21 != -1 && s22 != -1)
                ans = max(ans,sum-s21-s22);
        }
        else if(sum % 3 == 2) {
            if(s21 != -1)
                ans = max(ans,sum-s21);
            if(s11 != -1 && s12 != -1)
                ans = max(ans,sum-s11-s12);
        }
        else
            ans = sum;
        return ans;
    }
};