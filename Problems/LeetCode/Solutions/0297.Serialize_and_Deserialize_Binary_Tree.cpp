struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    void ser(TreeNode* node , string& s) {
        if(node == NULL)
            s += "NULL,";
        else {
            s += to_string(node->val) + ",";
            ser(node->left,s);
            ser(node->right,s);
        }
    }
    string serialize(TreeNode* root) {
        string s = "";
        ser(root,s);
        return s;
    }
    TreeNode* des(string& str , int& i) {
        string s = "";
        while(str[i] != ',')
            s.push_back(str[i++]);
        i++;
        if(s == "NULL")
            return NULL;
        int val = atoi(s.c_str());
        TreeNode* node = new TreeNode(val);
        node->left = des(str,i);
        node->right = des(str,i);
        return node;
    }
    TreeNode* deserialize(string str) {
        int i = 0;
        return des(str,i);
    }
};