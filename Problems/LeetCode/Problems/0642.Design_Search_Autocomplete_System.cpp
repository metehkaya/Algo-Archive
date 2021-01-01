typedef pair<int,string> pis;

class AutocompleteSystem {
public:
    struct Node {
        Node* next[27];
        int cnt;
        Node() {
            cnt = 0;
            memset(next, 0, sizeof(next));
        }
    };
    int toInt(char c) {
        return c == ' ' ? 26 : (c-'a');
    }
    char toChar(int i) {
        return i == 26 ? ' ' : ('a'+i);
    }
    Node* root;
    Node* curr;
    string currStr = "";
    void update( Node* node , int index , string& word , int times , bool isQuery = false ) {
        if(index == word.length()) {
            node->cnt += times;
            if(isQuery)
                curr = node;
            return;
        }
        int k = toInt(word[index]);
        if(node->next[k] == NULL)
            node->next[k] = new Node();
        update(node->next[k], index+1, word, times, isQuery);
    }
    void query( Node* node , vector<pis>& vec ) {
        if( node->cnt > 0 )
            vec.push_back( pis( node->cnt , currStr ) );
        for( int i = 0 ; i < 27 ; i++ )
            if( node->next[i] != NULL ) {
                char c = toChar(i);
                currStr.push_back(c);
                query(node->next[i],vec);
                currStr.pop_back();
            }
    }
    AutocompleteSystem(vector<string>& str, vector<int>& times) {
        root = new Node();
        curr = root;
        for( int i =  0 ; i < str.size() ; i++ ) {
            update(root,0,str[i],times[i]);
        }
    }
    vector<string> input(char c) {
        vector<string> ans;
        if(c == '#') {
            curr->cnt += 1;
            curr = root;
            currStr = "";
        }
        else {
            string str = "";
            str.push_back(c);
            currStr.push_back(c);
            update(curr, 0, str, 0, true);
            vector<pis> vec;
            query(curr, vec);
            sort( vec.begin( ), vec.end( ), [ ]( const pis& p1, const pis& p2 ) {
                if( p1.first != p2.first )
                    return p1.first > p2.first;
                return p1.second < p2.second;
            });
            for( int i = 0 ; i < min( (int) vec.size() , 3 ) ; i++ )
                ans.push_back( vec[i].second );
        }
        return ans;
    }
};