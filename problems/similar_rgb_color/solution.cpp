class Solution {
public:
    string similarRGB(string color) {
        char buf[8] = "#";
        for (int i = 1; i < color.length(); i+=2) {
            int v = stoi(color.substr(i, 2), nullptr, 16);
            int closest = int(round(v / 17.0)) * 17;
            snprintf(&buf[i], 3, "%02x", closest);
        }
        return buf;        
    }
};