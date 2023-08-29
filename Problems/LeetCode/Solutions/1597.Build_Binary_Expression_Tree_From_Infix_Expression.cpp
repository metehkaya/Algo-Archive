struct Node {
    char val;
    Node *left;
    Node *right;
    Node() : val(' '), left(nullptr), right(nullptr) {}
    Node(char x) : val(x), left(nullptr), right(nullptr) {}
    Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void makeExpr(stack<char>& ops, stack<Node*>& tree) {
        Node* root = new Node(ops.top());
        ops.pop();
        root->right = tree.top();
        tree.pop();
        root->left = tree.top();
        tree.pop();
        tree.push(root);
    }
    Node* expTree(string s) {
        unordered_map<char,int> priority;
        priority['('] = 1;
        priority['+'] = priority['-'] = 2;
        priority['*'] = priority['/'] = 3;
        priority['/'] = 3;
        stack<char> operators;
        stack<Node*> tree; 
        for( int i = 0 ; i < s.size() ; i++ ) {
            if(s[i] == '(')
                operators.push(s[i]);
            else if(isdigit(s[i])) {
                Node* node = new Node(s[i]);
                tree.push(node);                
            }
            else if(s[i] == ')') {
                while(!operators.empty() && operators.top() != '(')
                    makeExpr(operators, tree);
                operators.pop();
            }
            else {
                while(!operators.empty() && priority[operators.top()] >= priority[s[i]])
                    makeExpr(operators,tree);
                operators.push(s[i]);
            }
        }
        while(tree.size() > 1)
            makeExpr(operators,tree);
        return tree.top();
    }
};
