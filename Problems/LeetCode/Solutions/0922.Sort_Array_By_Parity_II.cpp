class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& ar) {
        int n = ar.size();
        vector<int> odd,even,ans;
        for( int i = 0 ; i < n ; i++ )
            if(ar[i]%2)
                odd.push_back(ar[i]);
            else
                even.push_back(ar[i]);
        for( int i = 0 ; i < n/2 ; i++ )
            ans.push_back(even[i]) , ans.push_back(odd[i]);
        return ans;
    }
};