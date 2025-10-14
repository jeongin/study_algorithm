class Solution:
    def maxArea(self, height: List[int]) -> int:
        left = 0
        right = len(height) - 1
        
        result = 0

        while left < right:
            h_left = height[left]
            h_right = height[right]
            result = max(result, (right - left) * min(h_left, h_right))

            if h_left < h_right:
                left += 1
            else:
                right -= 1

        return result



        