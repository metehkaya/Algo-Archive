class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        vector<int> cnt_suit(4,0);
        for( int i = 0 ; i < 5 ; i++ )
            cnt_suit[suits[i]-'a']++;
        for( int i = 0 ; i < 4 ; i++ )
            if(cnt_suit[i] == 5)
                return "Flush";
        vector<int> cnt_rank(13,0);
        for( int i = 0 ; i < 5 ; i++ )
            cnt_rank[ranks[i]-1]++;
        for( int i = 0 ; i < 13 ; i++ )
            if(cnt_rank[i] >= 3)
                return "Three of a Kind";
        for( int i = 0 ; i < 13 ; i++ )
            if(cnt_rank[i] >= 2)
                return "Pair";
        return "High Card";
    }
};
