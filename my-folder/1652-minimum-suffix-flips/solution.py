class Solution:
    def minFlips(self, target: str) -> int:

        flips = 0

        for letter in target:
            if int(letter)!=flips%2:
                flips += 1
        return flips





