class Solution {
public:

    int accountBalanceAfterPurchase(int purchaseAmount) {
  // Round the purchase amount to the nearest multiple of 10
    int roundedAmount = (purchaseAmount + 9) / 10 * 10;
        int prev = roundedAmount-10;
        int  res = 0;
    if(purchaseAmount - prev < roundedAmount - purchaseAmount) {
        res = prev;
    } else {
        res = roundedAmount;
    }
    cout << res << endl;
  // Subtract the rounded amount from the initial balance
  int balance = 100 - res;

  return balance;
    }

};
