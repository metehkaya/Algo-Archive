class Solution {
public:
    int n;
    map<string,int> mp;
    set<string> words[501];
    vector<string> topKFrequent(vector<string>& ar, int k) {
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ )
            mp[ar[i]]++;
        map<string,int>::iterator it;
        for( it = mp.begin() ; it != mp.end() ; it++ )
            words[it->second].insert(it->first);
        vector<string> ans;
        for( int freq = n ; freq >= 1 ; freq-- ) {
            set<string>::iterator iter;
            for( iter = words[freq].begin() ; iter != words[freq].end() && k > 0 ; iter++ , k-- )
                ans.push_back((*iter));
        }
        return ans;
    }
};