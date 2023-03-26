class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
           int sum = 0;



            // pick all positive items next
            int pos_items = min(numOnes, k);
            sum += pos_items * 1;
            k -= pos_items;

            // if there are still items left, pick zero items
            int zero_items = min(numZeros, k);
            k -= zero_items;
        
            if (k > 0) {
                sum += k * (-1);
            }


            return sum;
    }
};
