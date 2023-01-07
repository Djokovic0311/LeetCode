class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        int comp = 10000;
        bool isBulky = false, isHeavy = false;
        if(mass >= 100) isHeavy = true;
        long long v = (long long)length * (long long)width *(long long) height;
        if((length >= comp || width >= comp || height >= comp) || v >= 1000000000) {
            isBulky = true;
        }
        
        if(isBulky && isHeavy) return "Both";
        if(!isBulky && !isHeavy) return "Neither";
        if(isBulky && !isHeavy) return "Bulky";
        if(!isBulky && isHeavy) return "Heavy";
        return "";
    }
};
