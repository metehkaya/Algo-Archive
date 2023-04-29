class Solution {
public:
    string largestMultipleOfThree(vector<int>& ar) {
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
        string ans = "";
        if(sum % 3 == 1) {
            if(s11 != -1) {
                for( int i = n-1 ; i >= 0 ; i-- ) {
                    if( s11 == ar[i] )
                        s11 = -1;
                    else
                        ans.push_back('0'+ar[i]);
                }
            }
            else {
                for( int i = n-1 ; i >= 0 ; i-- ) {
                    if( s22 == ar[i] )
                        s22 = -1;
                    else if( s21 == ar[i] )
                        s21 = -1;
                    else
                        ans.push_back('0'+ar[i]);
                }
            }
        }
        else if(sum % 3 == 2) {
            if(s21 != -1) {
                for( int i = n-1 ; i >= 0 ; i-- ) {
                    if( s21 == ar[i] )
                        s21 = -1;
                    else
                        ans.push_back('0'+ar[i]);
                }
            }
            else {
                for( int i = n-1 ; i >= 0 ; i-- ) {
                    if( s12 == ar[i] )
                        s12 = -1;
                    else if( s11 == ar[i] )
                        s11 = -1;
                    else
                        ans.push_back('0'+ar[i]);
                }
            }
        }
        else {
            for( int i = n-1 ; i >= 0 ; i-- )
                ans.push_back('0'+ar[i]);
        }
        if(ans != "" && ans[0] == '0')
            return "0";
        return ans;
    }
};