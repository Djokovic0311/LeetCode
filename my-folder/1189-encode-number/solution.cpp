class Solution {
public:
    string encode(int num) {
        return bitset<32>(num+1).to_string().substr(__builtin_clz(num+1)+1);

    }
};
