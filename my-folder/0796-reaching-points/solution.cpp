class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        // in case of impossible cases
        if(tx < sx || ty < sy) return false;
        
        // to avoid the useless loop in those cases
        if(sx == tx) return (ty - sy) % sx == 0;
        
        if(sy == ty) return (tx - sx) % sy == 0;
        
        while(tx > sx && ty > sy) {
                  
            if(tx > ty)
                tx %= ty;
            else 
                ty %= tx;
        }
        cout << tx << ' '  << ty << endl;
        if(tx == sx) {
            if((ty - sy) % tx == 0)
                return true;
        } else if(ty == sy) {
            if((tx - sx) % ty == 0)
                return true;
        }
        
        return false;         
    }
};
