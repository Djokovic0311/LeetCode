class Solution {
public:
    string convertToTitle(int columnNumber) {
      
        string s="";
    columnNumber--;
    while(columnNumber>=0){
        s+=('A'+columnNumber%26);
        columnNumber/=26;
        columnNumber--;
    }
    reverse(s.begin(),s.end());
    return s;
      
    }
};
