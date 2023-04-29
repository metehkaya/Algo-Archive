class Solution {
public:
    string addBoldTag(string str, vector<string>& dict) {
        unordered_set<string> words;
        for( int i = 0 ; i < dict.size() ; i++ )
            words.insert(dict[i]);
        int n = str.length();
        vector<pair<int,int>> v;
        for( int i = 0 ; i < n ; i++ ) {
            string word = "";
            for( int j = i ; j < n ; j++ ) {
                word.push_back(str[j]);
                if( words.find(word) != words.end() )
                    v.push_back(make_pair(i,j+1));
            }
        }
        sort(v.begin(), v.end());
        pair<int,int> curr = make_pair(-1,-1);
        vector<int> next(n,-1);
        for( int i = 0 ; i < v.size() ; i++ ) {
            int s = v[i].first;
            int e = v[i].second;
            if( curr.first == -1 )
                curr = make_pair(s,e);
            else if( curr.second < s ) {
                next[curr.first] = curr.second;
                curr = make_pair(s,e);
            }
            else
                curr.second = max( curr.second , e );
        }
        if(curr.first != -1)
            next[curr.first] = curr.second;
        string ans = "";
        int index = 0;
        while(index < n) {
            if(next[index] == -1)
                ans.push_back(str[index++]);
            else {
                ans += "<b>";
                ans += str.substr(index, next[index]-index);
                ans += "</b>";
                index = next[index];
            }
        }
        return ans;
    }
};
