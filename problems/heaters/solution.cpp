class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int radius = 0;
        sort(heaters.begin(), heaters.end());
        for(auto house : houses) {
            if(house <= heaters.front()) {
                radius = max(radius, heaters.front() - house);
                continue;
            }
            if(house >= heaters.back()) {
                radius = max(radius, house - heaters.back());
                continue;
            }
            radius = max(radius, findAjacentHeaters(house, heaters));
        }
        return radius;
    }
private:
    int findAjacentHeaters(int house, vector<int>& heaters) {
        int radius = 0;
        int l = 0;
        int r = heaters.size() - 1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(heaters[mid] == house) return 0;
            if(heaters[mid] < house) l = mid + 1;
            if(heaters[mid] > house) r = mid - 1;
        }
        return min(heaters[l]-house, house-heaters[r]);
    }
};