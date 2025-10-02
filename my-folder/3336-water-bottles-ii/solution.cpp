class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int res = numBottles;
        int emptyBottle = numBottles;
        while(emptyBottle >= numExchange) {
            emptyBottle -= numExchange++-1;
            res++;
        }
        return res;
    }
};
