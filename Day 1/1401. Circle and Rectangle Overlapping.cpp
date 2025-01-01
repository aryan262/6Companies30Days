class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        auto clamp = [&](int center, int k, int mx) {
            return max(k, min(mx, center));
        };
        int a = clamp(xCenter, x1, x2);
        int b = clamp(yCenter, y1, y2);
        int distX = xCenter-a;
        int distY = yCenter-b;
        return (distX*distX)+(distY*distY)<=(radius*radius);
    }
};
