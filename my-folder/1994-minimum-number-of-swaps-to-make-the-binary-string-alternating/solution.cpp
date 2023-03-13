class Solution {
public:
    int minSwaps(string s) {
        int n = s.length();
        int one = 0, zero = 0;
        for(char c : s) {
            if(c == '1')
                one++;
            else zero++;
        }
        if(abs(one-zero) > 1) return -1;
        int uncommon_1 = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(i % 2 == 0)
            {
                if(s[i] != '0')
                {
                    uncommon_1++;
                }
            }
            else
            {
                if(s[i] != '1')
                {
                    uncommon_1++;
                }
            }
        }
        int uncommon_2 = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(i % 2 == 1)
            {
                if(s[i] != '0')
                {
                    uncommon_2++;
                }
            }
            else
            {
                if(s[i] != '1')
                {
                    uncommon_2++;
                }
            }
        }
        int mini = INT_MAX;
        
        if(uncommon_1 % 2 == 0)
        {
            mini = min(mini, uncommon_1);
        }
        
        if(uncommon_2 % 2 == 0)
        {
            mini = min(mini, uncommon_2);
        }
        if(mini == INT_MAX)
            return -1;
        return (mini) / 2;           
    }
};
