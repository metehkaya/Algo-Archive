class Solution {
public:
    int maxFont(string text, int w, int h, vector<int>& fonts, FontInfo fontInfo) {
        int n = fonts.size();
        int l = 0 , r = n-1 , ans = -1;
        while(l <= r) {
            int m = (l+r) >> 1;
            int height = fontInfo.getHeight(fonts[m]);
            int width = w;
            bool ok = true;
            for(char c : text) {
                width -= fontInfo.getWidth(fonts[m],c);
                if(width < 0) {
                    ok = false;
                    break;
                }
            }
            if(ok and height <= h)
                l = m+1 , ans = fonts[m];
            else
                r = m-1;
        }
        return ans;
    }
};
