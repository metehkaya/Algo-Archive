class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n = s.length() , na = a.length() , nb = b.length();
        vector<int> va,vb;
        for( int i = 0 ; i <= n-na ; i++ )
            if(s.substr(i,na) == a)
                va.push_back(i);
        for( int i = 0 ; i <= n-nb ; i++ )
            if(s.substr(i,nb) == b)
                vb.push_back(i);
        vector<int> ans;
        for(int idx : va) {
            auto it1 = lower_bound(vb.begin(),vb.end(),idx-k);
            auto it2 = upper_bound(vb.begin(),vb.end(),idx+k);
            if(it2-it1 > 0)
                ans.push_back(idx);
        }
        return ans;
    }
};
