class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> myset;
        int n = emails.size();
        for( int i = 0 ; i < n ; i++ ) {
            int len = emails[i].size();
            int indexDomain = 0;
            bool isPlus = false;
            string localName = "";
            while(indexDomain < len && emails[i][indexDomain] != '@') {
                if(!isPlus) {
                    if(emails[i][indexDomain] == '+')
                        isPlus = true;
                    else if(emails[i][indexDomain] != '.')
                        localName = localName + emails[i][indexDomain];
                }
                indexDomain++;
            }
            string email = localName + emails[i].substr(indexDomain,len-indexDomain);
            myset.insert(email);
        }
        return myset.size();
    }
};