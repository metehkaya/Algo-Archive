class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long long a,b,c,d,e,f,g,h;
        a=A,b=B,c=C,d=D,e=E,f=F,g=G,h=H;
        long long leftX = max(a,e);
        long long rightX = min(c,g);
        long long bottomY = max(b,f);
        long long topY = min(d,h);
        long long total = (c-a)*(d-b) + (g-e)*(h-f);
        total -= max(rightX-leftX,0LL) * max(topY-bottomY,0LL);
        return (int)total;
    }
};