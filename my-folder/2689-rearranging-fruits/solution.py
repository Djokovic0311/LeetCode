class Solution:
    def minCost(self, arr1: List[int], arr2: List[int]) -> int:

        n=len(arr1)

        flag = False
        mini = 2 << 30
        el = set()
        movefromA = []
        movefromB = []
        lengtha=lengthb=0

        number1 = {}
        number2 = {}
        for i in arr1:
            if (i in number1):
                number1[i] += 1
            else:
                number1[i] = 1
                number2[i] = 0
                el.add(i)

        for i in arr2:
            if (i in number2):
                number2[i] += 1
            else:
                number2[i] = 1
                if i not in el:
                    number1[i] = 0
                    el.add(i)

        for i in el:
            a = number1[i]
            b = number2[i]
            total = a + b
            if total%2!=0:
                flag = True
                break

            if(mini > i):
                mini = i

            if(a < b):
                for j in range((b - a) >> 1):
                    movefromB.append(i)
                    lengthb += 1
            elif(b < a):
                for j in range((a - b) >> 1):
                    movefromA.append(i)
                    lengtha += 1

        if(lengtha != lengthb):
            flag = True

        if(flag):
            return -1

        movefromA.sort()
        movefromB.sort()

        mini *= 2

        lessMinA = 0
        lessMinB = 0
        for i in movefromA:
            if i > mini:
                break
            lessMinA += 1
        greatMinA = lengtha - lessMinA

        for i in movefromB:
            if i > mini:
                break
            lessMinB += 1
        greatMinB = lengthb - lessMinB

        pay = 0

        if(lessMinA <= greatMinB):
            for i in movefromA[:lessMinA]:
                pay += i
            for i in movefromB[:lessMinB]:
                pay += i
            pay += (mini * (greatMinA - lessMinB))

        else:
            for i in movefromA[:(greatMinB)]:
                pay += i
            for i in movefromB[:(greatMinA)]:
                pay += i

            i = greatMinB
            j = greatMinA
            for k in range(lessMinB - greatMinA):
                if(movefromA[i] < movefromB[j]):
                    pay += movefromA[i]
                    i += 1
                else:
                    pay += movefromB[j]
                    j += 1


        return pay
