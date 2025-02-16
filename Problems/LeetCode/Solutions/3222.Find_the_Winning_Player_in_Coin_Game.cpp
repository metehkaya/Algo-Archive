class Solution {
public:
    string winningPlayer(int x, int y) {
        int k = min(x,y/4);
        return (k % 2) == 1 ? "Alice" : "Bob";
    }
};