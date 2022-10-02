class Solution:

    def deleteString(self, s: str) -> int:
        def helper(string, mem):
            if string in mem:
                return mem[string]

            n = len(string)

            if n == 1:
                mem[string] = 1
                return 1
            if n == 2:
                if string[0] != string[1]:
                    mem[string] = 1
                    return 1
                mem[string] = 2
                return 2

            maxSteps = 1
            for i in range(1, int(n / 2) + 1):
                if string[:i] == string[i:2*i]:
                    steps = 1 + helper(string[i:], mem)
                    if steps > maxSteps:
                        maxSteps = steps

            mem[string] = maxSteps
            return maxSteps

        valid = True
        tmp = s[0]
        l = len(s)
        for c in s:
            if c != tmp:
                valid = False
        if valid == True:
            return l
        mem = {}
        # print(len(s))
        # return 0
        return helper(s, mem)
