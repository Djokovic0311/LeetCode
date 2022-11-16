/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int start = 1 , end = n;
        while(start <= end){
            int mid = start + (end - start) / 2;
            int ans = guess(mid);
            if(ans == 0)
                return mid;
            else if( ans == 1)
                start = mid + 1;
            else 
                end = mid ;
        }
        return 0;
    }
};