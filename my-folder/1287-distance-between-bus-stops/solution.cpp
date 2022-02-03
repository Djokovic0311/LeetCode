class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int d1 = 0, d2 = 0;
        int i = 0;
        int n = distance.size();
        if(start > destination) swap(start, destination);
        while(i < n) {
            if(i >= start && i < destination) d1 += distance[i];
            else d2 += distance[i];
            i++;
        }
        return min(d1,d2);
    }
};
