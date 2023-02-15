class Solution:
    def isReflected(self, points: List[List[int]]) -> bool:
        if not points:
            return True

        x_min = float('inf')
        x_max = float('-inf')
        point = dict()

        for x, y in points:
            key = (x, y)

            if key not in point:
                point[key] = 1

            if x < x_min:
                x_min = x
            if x > x_max:
                x_max = x

        middle = (x_max + x_min) / 2

        for x, y in points:

            exp = 2 * middle - x
            key = (exp, y)
            val = point.get(key)

            if val:
                if val > 1:
                    point[key] -= 1
                else:
                    del point[key]

        return not point
