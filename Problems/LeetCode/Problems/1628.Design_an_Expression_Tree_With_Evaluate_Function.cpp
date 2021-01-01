class Node {
public:
    Node(int val) : val(val) {};
    Node(char type, Node *left, Node *right) : type(type), left(left), right(right) {};
    virtual ~Node () {};
    virtual int evaluate() {
        int res;
        if(type == 0)
            res = val;
        else {
            int l = left->evaluate();
            int r = right->evaluate();
            if(type == '+')
                res = l+r;
            else if(type == '-')
                res = l-r;
            else if(type == '*')
                res = l*r;
            else
                res = l/r;
        }
        return res;
    }
protected:
    int val = 0;
    char type = 0;
    Node* left = NULL;
    Node* right = NULL;
};

class TreeBuilder {
public:
    Node* buildTree(vector<string>& v) {
        int n = v.size();
        stack<Node*> st;
        for( int i = 0 ; i < n ; i++ ) {
            string s = v[i];
            if(s == "+" || s == "-" || s == "*" || s == "/") {
                Node* r = st.top();
                st.pop();
                Node* l = st.top();
                st.pop();
                st.push(new Node(s[0],l,r));
            }
            else {
                int num = stoi(s);
                st.push(new Node(num));
            }
        }
        Node* res = st.top();
        st.pop();
        return res;
    }
};