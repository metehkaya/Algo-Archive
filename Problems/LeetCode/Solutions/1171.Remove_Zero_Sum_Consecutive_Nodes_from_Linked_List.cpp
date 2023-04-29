struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int> v;
        while(head != NULL) {
            v.push_back(head->val);
            head = head->next;
        }
        bool ok = true;
        while(ok) {
            ok = false;
            map<int,int> idx;
            idx[0] = 0;
            int n = v.size();
            for( int i = 0 , sum = 0 ; i < n ; i++ ) {
                sum += v[i];
                auto it = idx.find(sum);
                if(it == idx.end())
                    idx[sum] = i+1;
                else {
                    ok = true;
                    int s = it->second;
                    v.erase( v.begin()+s , v.begin()+i+1 );
                    break;
                }
            }
        }
        if(!v.empty()) {
            int n = v.size();
            head = new ListNode(v[0]);
            ListNode* node = head;
            for( int i = 1 ; i < n ; i++ ) {
                node->next = new ListNode(v[i]);
                node = node->next;
            }
        }
        return head;
    }
};