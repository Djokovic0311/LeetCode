class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int l = flowerbed.size();
        int count = 0;
        for(int i = 0; i < l; i++) {
            if(flowerbed[i] == 0) {
                bool validLeft = i == 0? true : flowerbed[i-1] == 0;
                bool validRight = i == l-1 ? true: flowerbed[i+1] == 0;
                if(validLeft && validRight) {
                    flowerbed[i] =1;
                    n--;
                }
                if(n <= 0) break;
            }
        }
        return n <= 0;

    }
};
