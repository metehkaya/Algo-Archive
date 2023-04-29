class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        vector<int> v;
        for( int i = 0 ; i < n ; i++ )
            if(words[i] == target)
                v.push_back(i);
        if(v.empty())
            return -1;
        int ans = n;
        for(int idx : v) {
            int a = startIndex;
            int b = idx;
            if(a > b)
                swap(a,b);
            ans = min(ans,b-a);
            ans = min(ans,n-(b-a));
        }
        return ans;
    }
};
