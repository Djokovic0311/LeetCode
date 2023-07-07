class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(maxConsecutiveChars(answerKey, 'T', k), maxConsecutiveChars(answerKey, 'F', k));
    
    }
    int maxConsecutiveChars(string &answerKey, char ch, int k) {
        int left = 0, right = 0, maxLen = 0, flipCount = 0;
        
        while (right < answerKey.length()) {
            if (answerKey[right] != ch) {
                flipCount++;
            }
            
            while (flipCount > k) {
                if (answerKey[left] != ch) {
                    flipCount--;
                }
                left++;
            }
            
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        
        return maxLen;
    }
};
