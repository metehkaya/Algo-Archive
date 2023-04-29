class Solution {
public:
    int kSimilarity(string A, string B) {
        int n = A.length();
        queue<string> Q;
        unordered_map<string,int> mp;
        unordered_map<string,int>::iterator it;
        Q.push(A);
        mp[A] = 0;
        while(!Q.empty()) {
            string s = Q.front();
            Q.pop();
            int cost = mp[s];
            if(s == B)
                return cost;
            int idx = 0;
            while(s[idx] == B[idx])
                idx++;
            for( int i = idx+1 ; i < n ; i++ )
                if(s[i] == B[idx]) {
                    swap(s[i],s[idx]);
                    it = mp.find(s);
                    if(it == mp.end()) {
                        Q.push(s);
                        mp[s] = cost+1;
                    }
                    swap(s[i],s[idx]);
                }
        }
        return -1;
    }
};