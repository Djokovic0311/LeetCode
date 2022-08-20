class Solution(object):
    def secondsToRemoveOccurrences(self, s):
        """
        :type s: str
        :rtype: int
        """
        res = 0
        while s.find('01') != -1:
            s = s.replace('01','10')
            res+=1
        return res
        