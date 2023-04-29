class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Codec {
public:
    void dfs_serialize(Node* node, string& s) {
        s.push_back('[');
        s += to_string(node->val);
        for(Node* child : node->children)
            dfs_serialize(child,s);
        s.push_back(']');
    }
    string serialize(Node* root) {
        string s = "";
        if(root != NULL)
            dfs_serialize(root,s);
        return s;
    }
    Node* dfs_deserialize(string& s, int& idx) {
        idx++;
        int val = 0;
        while(s[idx] >= '0' and s[idx] <= '9')
            val = 10*val + s[idx++]-'0';
        Node* node = new Node(val);
        while(s[idx] != ']')
            node->children.push_back(dfs_deserialize(s,idx));
        idx++;
        return node;
    }
    Node* deserialize(string s) {
        if(s == "")
            return NULL;
        int idx = 0;
        return dfs_deserialize(s,idx);
    }
};
