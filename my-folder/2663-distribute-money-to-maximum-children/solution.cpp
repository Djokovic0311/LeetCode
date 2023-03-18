class Solution {
public:
    int distMoney(int money, int children) {
        if(money < children) return -1;
        if(money == children || money < 8) return 0;
        int remaining_money = money - children;
        
        int max_eights = remaining_money / 7;
        remaining_money -= max_eights * 7;
        
        int remaining_children = children - max_eights;
        if(remaining_children < 0) return children-1;
        int have_to_four = 0;
        // cout << remaining_children << " " << remaining_money;
        if(remaining_money == 3 && remaining_children == 1 || remaining_children == 0 && remaining_money!= 0) 
            return max_eights-1;
        else return max_eights;
    }
};
