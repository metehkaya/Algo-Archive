class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& ar, int a, int b, int c) {
        int n = ar.size();
        double med = (-b) / (2.0*a);
        vector<int> ans;
        for( int i = 0 , j = n-1 ; i <= j ; ) {
            double l = fabs(med-ar[i]);
            double r = fabs(med-ar[j]);
            if(l >= r) {
                ans.push_back(a*ar[i]*ar[i]+b*ar[i]+c);
                i++;
            }
            else {
                ans.push_back(a*ar[j]*ar[j]+b*ar[j]+c);
                j--;
            }
        }
        if(ans[0] > ans[n-1])
            reverse(ans.begin(),ans.end());
        return ans;
    }
};