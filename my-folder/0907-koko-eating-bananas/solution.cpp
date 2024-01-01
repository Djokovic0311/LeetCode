class Solution {
public:
    int calcTime(vector<int>& piles, int speed) {
        int hours = 0;
        for(int p : piles) {
            if(p < speed) hours++;
            else {
                hours += (p % speed == 0) ? p/speed : p/speed+1;
            }
        }

        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int sum = 0;
        int n = piles.size();
        int left = 1, right = *max_element(piles.begin(), piles.end());
        while(left < right) {
            int mid = left + (right-left)/2;
            int hours = calcTime(piles, mid);
            if(hours >h) {
                left = mid+1;
            } else {
                right = mid;
            }
        }

        return left;
    }
};
