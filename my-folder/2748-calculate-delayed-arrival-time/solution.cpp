class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        int actualArrivalTime = (arrivalTime + delayedTime) % 24;
        return actualArrivalTime;
    }
};
