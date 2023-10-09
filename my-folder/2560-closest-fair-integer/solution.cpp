class Solution {
public:
    int closestFair(int n) {
        while(true){
            string s = to_string(n);
            int sz = int(s.size());
            if (sz & 1){ // make it even length
                n = pow(10, sz++);
                s = to_string(n);
            }
            if (count_if(begin(s), end(s), [](char c){return (c-'0')&1;}) == sz/2){
                return n;
            }
            n++;
        }
    }
};
