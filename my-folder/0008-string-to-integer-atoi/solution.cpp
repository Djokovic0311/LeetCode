class Solution {
public:
    int myAtoi(string s) {
        int len = s.length();
        if(len == 0) return 0;
        int index = 0;
        bool isNeg = false;
        while(index < len && s[index]==' ') index++;
        if(index < len){
          if(s[index] == '-'){
            isNeg = true;
            ++index;
          } else if (s[index] == '+'){
              ++index;
          }
        }
    int result = 0;

    while(index < len && isDigit(s[index])){
      int digit = s[index] - '0';
      if(result > (INT_MAX / 10) || (result == (INT_MAX / 10) && digit > 7)){
          return isNeg ? INT_MIN : INT_MAX;
      }
      result = (result * 10) + digit; 

      ++index;
    }
      
    return isNeg ? -result : result;
  }
    
private:
  bool isDigit(char ch){
    return ch >= '0' && ch <= '9';
  }
    
};

