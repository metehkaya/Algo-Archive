class Solution {
public:
    vector<int> getVec(int x , int lim) {
        vector<int> v(1,1);
        if(x > 1)
            while(v.back()*x <= lim) {
                int add = v.back()*x;
                v.push_back(add);
            }
        return v;
    }
    vector<int> powerfulIntegers(int x, int y, int lim) {
        vector<int> ans;
        if(lim < 2)
            return ans;
        vector<int> a = getVec(x,lim);
        vector<int> b = getVec(y,lim);
        set<int> s;
        for( int i = 0 ; i < a.size() ; i++ )
            for( int j = 0 ; j < b.size() ; j++ )
                if(a[i] + b[j] <= lim)
                    s.insert(a[i]+b[j]);
        ans.resize(s.size());
        copy(s.begin(),s.end(),ans.begin());
        return ans;
    }
};