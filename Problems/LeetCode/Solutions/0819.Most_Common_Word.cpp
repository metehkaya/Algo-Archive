class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        bool isPunc[256] = {0};
        isPunc['!']=isPunc['?']=isPunc['\'']=isPunc[',']=isPunc[';']=isPunc['.']=isPunc[' ']=true;
        unordered_set<string> hashBan;
        for( int i = 0 ; i < banned.size() ; i++ )
            hashBan.insert(banned[i]);
        unordered_map<string,int> hashCnt;
        unordered_map<string,int>::iterator iter;
        string ans="";
        int mxCnt = 0;
        paragraph.push_back('.');
        string curr = "";
        for( int i = 0 ; i < paragraph.length() ; i++ ) {
            char c = paragraph[i];
            if(isPunc[c]) {
                if(curr != "") {
                    if(hashBan.find(curr) == hashBan.end()) {
                        iter = hashCnt.find(curr);
                        if(iter == hashCnt.end()) {
                            hashCnt.insert(make_pair(curr,1));
                            if(mxCnt == 0)
                                ans = curr, mxCnt = 1;
                        }
                        else {
                            int cnt = (iter->second) + 1;
                            iter->second++;
                            if(cnt > mxCnt)
                                ans = curr, mxCnt = cnt;
                        }
                    }
                    curr = "";
                }
            }
            else {
                if(c < 'a')
                    c = c - 'A' + 'a';
                curr.push_back(c);
            }
        }
        return ans;
    }
};