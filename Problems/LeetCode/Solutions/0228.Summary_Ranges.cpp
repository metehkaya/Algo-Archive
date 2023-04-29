class Solution {
public:
    string conv(int x , int y) {
        if(x == y)
            return to_string(x);
        return to_string(x) + "->" + to_string(y);
    }
    vector<string> summaryRanges(vector<int>& ar) {
        int n = ar.size();
        vector<string> ans;
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            while(j < n && ar[j] == ar[i]+(j-i))
                j++;
            ans.push_back(conv(ar[i],ar[j-1]));
        }
        return ans;
    }
};