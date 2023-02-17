# return True if ans[-1] + ans[-1] == num[start_idx:start_idx+digit+1]
def is_fibo_eligible(s, ans, start_idx):
    if (start_idx == len(s) and len(ans) >= 3):
            return True
    for end_idx in range(start_idx+1, len(s)+1):
        current_number = int(s[start_idx:end_idx])
        current_number_digit = end_idx - start_idx
        # starts with 0 while digit > 1
        if (current_number_digit > 1) and s[start_idx:end_idx][0] == '0':
            return False
        # valid case where len(ans) <= 1 or fibo valid
        if (current_number > 2**31 - 1):
            return False
        # early termination because there is no way current_number 
        # would be smaller in the next iteration
        elif (len(ans) >= 2 and (current_number > ans[-2] + ans[-1])):
        	return False
        elif (len(ans) <= 1 or (ans[-2] + ans[-1] == current_number)):
            ans.append(current_number)
            # move the index
            # short-cut if is_fibo_eligible = True
            if is_fibo_eligible(s, ans, start_idx + current_number_digit):
                return True
            else:
                # else remove the last element because it is wrong
                ans.pop()        
        
    return False
class Solution:
    def splitIntoFibonacci(self, num: str) -> List[int]:
        ans = []
        is_fibo_eligible(num, ans, 0)
        return ans
