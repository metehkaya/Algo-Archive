class Solution {
public:
    int minOperations(vector<int>& ar) {
        int n = ar.size();
        vector<int> odd,even;
        for( int i = 0 ; i < n ; i++ )
            if(ar[i]%2)
                odd.push_back(ar[i]);
            else if(ar[i])
                even.push_back(ar[i]);
        int ans = 0;
        while(true) {
            if(odd.empty() && even.empty())
                break;
            vector<int> add;
            for( int i = 0 ; i < even.size() ; i++ )
                add.push_back(even[i]);
            for( int i = 0 ; i < odd.size() ; i++ )
                if(odd[i] > 1)
                    add.push_back(odd[i]-1);
            ans += (int) odd.size();
            odd.clear();
            if(odd.empty() && even.empty() && add.empty())
                break;
            even.clear();
            ans++;
            for( int i = 0 ; i < add.size() ; i++ ) {
                int num = add[i]/2;
                if(num%2)
                    odd.push_back(num);
                else
                    even.push_back(num);
            }
        }
        return ans;
    }
};