# One pass solution using two pointers:
# (Similar to first solution, but requires only one pass)
class Solution:
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        left, right = 0, len(height) - 1
        ans = 0
        left_max, right_max = 0, 0
        while left < right:
            # If left ht < right ht, move left ptr. Else move rt
            if height[left] < height[right]:
                left_max = max(left_max, height[left])
                # Water trapped is the delta of the max ht and curr ht
                ans += left_max - height[left]
                left += 1
            else:
                right_max = max(right_max, height[right])
                ans += right_max - height[right]
                right -= 1
        return ans
