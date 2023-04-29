struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* str2tree(string s) {
        stack<TreeNode*> st;
        int len = s.length();
        for( int i = 0 ; i < len ; ) {
            if(s[i] == '(')
                i++;
            else if(s[i] == ')') {
                i++;
                st.pop();
            }
            else {
                bool isNeg = false;
                if(s[i] == '-')
                    i++ , isNeg = true;
                int num = 0;
                while(i < len && s[i] != '(' && s[i] != ')') {
                    num *= 10;
                    int dig = s[i]-'0';
                    if(isNeg)
                        num -= dig;
                    else
                        num += dig;
                    i++;
                }
                TreeNode* node = new TreeNode(num);
                if(st.empty())
                    st.push(node);
                else {
                    TreeNode* p = st.top();
                    st.push(node);
                    if(p->left == NULL)
                        p->left = node;
                    else
                        p->right = node;
                }
            }
        }
        if(st.empty())
            return NULL;
        return st.top();
    }
};