class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        prefix=strs[0]
        for i in range(1,len(strs)):
            while strs[i].find(prefix)!=0:
                length=len(prefix)
                prefix=prefix[0:length-1]
                if len(prefix)==0:
                    return ""
        return prefix   


