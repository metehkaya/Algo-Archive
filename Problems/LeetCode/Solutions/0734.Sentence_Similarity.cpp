class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        int n = words1.size();
        int m = words2.size();
        if(n != m)
            return false;
        set<pair<string,string>> sim;
        for( int i = 0 ; i < pairs.size() ; i++ ) {
            string s = pairs[i][0];
            string t = pairs[i][1];
            sim.insert( make_pair( s,t ) );
            sim.insert( make_pair( t,s ) );
        }
        for( int i = 0 ; i < n ; i++ ) {
            string s = words1[i];
            string t = words2[i];
            if(s == t)
                continue;
            if(sim.find(make_pair(s,t)) == sim.end())
                return false;
        }
        return true;
    }
};