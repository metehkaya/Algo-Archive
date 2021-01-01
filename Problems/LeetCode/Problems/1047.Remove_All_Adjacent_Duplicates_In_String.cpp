class Solution {
public:
    string removeDuplicates(string str) {
        int n = str.length();
        vector<int> prev(n);
        vector<int> next(n);
        for( int i = 0 ; i < n ; i++ )
            prev[i]=i-1 , next[i]=i+1;
        int head=0,index=0;
        while(index < n && next[index] < n) {
            int ni = next[index];
            if(str[index] == str[ni]) {
                if(head == index)
                    head = index = next[ni];
                else {
                    next[prev[index]] = next[ni];
                    if(next[ni] != n)
                        prev[next[ni]] = prev[index];
                    index = prev[index];
                }
            }
            else
                index = ni;
        }
        string ans = "";
        for( int i = head ; i < n ; i = next[i] )
            ans.push_back(str[i]);
        return ans;
    }
};