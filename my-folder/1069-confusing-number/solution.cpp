class Solution {
public:
    bool confusingNumber(int n) {
        int newNumber = 0;
        int oldNumber = n;
        while(n){ //Keep iterating until n is 0
            int x = n % 10; //Extract the least significant number (LSN)
            if (x == 2 || x == 3 || x == 4 || x == 5 || x == 7){ //Any time you see these numbers you know it is are invalid
                return false;
            }
            newNumber = newNumber * 10 + ((x == 6 || x == 9) ? (x == 6 ? 9 : 6): x); //LSN becomes most significant number, replace 6 with 9 and 9 wth 6
            n /= 10; //Remove the LSN and move on to the next number
        }
        return newNumber != oldNumber; //the newly constructed number cannot equal to original number
    }
};
