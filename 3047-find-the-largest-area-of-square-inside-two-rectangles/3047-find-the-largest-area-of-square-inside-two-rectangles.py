class Solution:
    def largestSquareArea(self, bottomLeft, topRight):
        n = len(bottomLeft)
        max_area = 0

        for i in range(n):
            for j in range(i + 1, n):
                x_left = max(bottomLeft[i][0], bottomLeft[j][0])
                y_bottom = max(bottomLeft[i][1], bottomLeft[j][1])
                x_right = min(topRight[i][0], topRight[j][0])
                y_top = min(topRight[i][1], topRight[j][1])
                if x_left < x_right and y_bottom < y_top:
                    side = min(x_right - x_left, y_top - y_bottom)
                    max_area = max(max_area, side * side)

        return max_area