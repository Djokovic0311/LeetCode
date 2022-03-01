class Solution {
public:
    int balancedStringSplit(string s) {
        const size_t SIZE1{ s.size() };

        int counter = 0;
        int res = 0;

        for(size_t i = 0; i < SIZE1; i++)
        {
            if(s[i] == 'R')
            {
                counter++;
            }
            else
            {
                counter--;
            }

            if(counter == 0)
            {
                res++;
            }
        }

        return res;
    }
};
