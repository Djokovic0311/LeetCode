def isVaild(word):
    vowels = ['a', 'e', 'i', 'o', 'u']
    return word[0] in vowels and word[-1] in vowels
class Solution:

    
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        record = []
        record.append(0)
        for word in words:
            record.append(isVaild(word))
        for i in range(len(record)):
            if i != 0:
                record[i] += record[i-1]
        print(record)
        res = []
        for q in queries:
            res.append(record[q[1]+1]-record[q[0]])
        return res
