#define fi first
#define se second
typedef pair<int,int> pi;

class Solution {
public:
    string s;
    int other[100003];
    pi f(int l , int r) {
        if(l == r)
            return pi(s[l]-'0',1);
        if(other[l] == r)
            return f(l+1,r-1);
        pi left,right;
        char op;
        if(other[r] != -1) {
            int id = other[r];
            op = s[id-1];
            left = f(l,id-2);
            right = f(id,r);
        }
        else {
            op = s[r-1];
            left = f(l,r-2);
            right = f(r,r);
        }
        int val;
        int cost;
        if(op == '&') {
            if(left.fi == 0 && right.fi == 0) {
                val = 0;
                cost = min(left.se,right.se)+1;
            }
            else if(left.fi == 0 && right.fi == 1) {
                val = 0;
                cost = 1;
            }
            else if(left.fi == 1 && right.fi == 0) {
                val = 0;
                cost = 1;
            }
            else {
                val = 1;
                cost = min(left.se,right.se);
            }
        }
        else {
            if(left.fi == 0 && right.fi == 0) {
                val = 0;
                cost = min(left.se,right.se);
            }
            else if(left.fi == 0 && right.fi == 1) {
                val = 1;
                cost = 1;
            }
            else if(left.fi == 1 && right.fi == 0) {
                val = 1;
                cost = 1;
            }
            else {
                val = 1;
                cost = min(left.se,right.se)+1;
            }
        }
        return pi(val,cost);
    }
    int minOperationsToFlip(string str) {
        s = str;
        int len = s.length();
        stack<int> st;
        memset(other,-1,sizeof(other));
        for( int i = 0 ; i < len ; i++ ) {
            if(s[i] == '(')
                st.push(i);
            else if(s[i] == ')') {
                int id = st.top();
                st.pop();
                other[id] = i;
                other[i] = id;
            }
        }
        return f(0,len-1).se;
    }
};