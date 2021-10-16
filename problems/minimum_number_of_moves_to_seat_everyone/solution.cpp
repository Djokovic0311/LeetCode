class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int res = 0;
        int n = seats.size();
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        for(int i = 0; i < n; i++) {
            res = res + abs(seats[i] - students[i]);
        }
        return abs(res);
    }
};