class Solution {
public:
    int numberOfDays(int year, int month) {
        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int result = days[month - 1];
        if(((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && month == 2) {
            return result+1;
        }
        return result;
    }
};
