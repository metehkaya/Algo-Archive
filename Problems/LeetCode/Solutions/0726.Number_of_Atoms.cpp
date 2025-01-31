class Solution {
public:
    string countOfAtoms(string s) {
        map<string, int> atoms;
        string ans;
        int cnt = 0, mult = 1;
        stack<int> st;
        for( int i = s.length() - 1;  i >= 0 ; i-- ) {
            if(isalpha(s[i]) and islower(s[i])) {
                int len = 2;
                i--;                
                while(i >= 0 and islower(s[i])) {
                    i--;
                    len++;
                }
                string atom = s.substr(i, len);
                atoms[atom] += max(cnt, 1) * mult;
                cnt = 0;
            }
            else if(isalpha(s[i]) and isupper(s[i])) {
                string atom(1, s[i]);
                atoms[atom] += max(cnt, 1) * mult;
                cnt = 0;
            }
            else if(isdigit(s[i])) {
                cnt = s[i] - '0';
                int p = 10;                
                while(i - 1 >= 0 and isdigit(s[i - 1])) {
                    cnt += p * (s[--i] - '0');
                    p *= 10;
                }
            }
            else if(s[i] == ')') {
                st.push(mult);
                mult *= max(cnt, 1);
                cnt = 0;
            }
            else {
                mult = st.top();
                st.pop();
            }
        }
        for(auto [atom, count]: atoms) {
            ans += atom;
            if(count > 1)
                ans += to_string(count);
        }
        return ans;
    }
};