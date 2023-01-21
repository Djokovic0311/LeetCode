class Solution {
public:
    bool reach(int sx, int sy, int dx, int dy)
    {
        // base case
       
        
        cout << "source" <<endl;
        cout << sx << ' ' << sy << endl;
        cout << "destination" <<endl;
        cout << dx << ' ' << dy << endl;
        
        if ((sx != 1 && sx < dx) || (sy != 1 && sy < dy))
            return false;

        if (sx == dx && sy == dy)
            return true;

        return (reach(sx - sy, sy, dx, dy) ||
                reach(sx, sy - sx, dx, dy) ||
                reach(sx * 2, sy, dx, dy) ||
                reach(sx, sy * 2, dx, dy));
    }
    bool isReachable(int x, int y) {
        int v = gcd(x, y);
        while (v % 2 == 0)
            v /= 2;
        return v == 1;
        
    }
};
