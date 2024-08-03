class Solution:
    def trap(self, height):
        ans = 0
        current = 0
        st = []
        while current < len(height):
            while len(st) != 0 and height[current] > height[st[-1]]:
                top = st[-1]
                st.pop()
                # No more left bar to trap water, so exit loop
                if len(st) == 0:
                    break
                # width of area to be filled with water
                distance = current - st[-1] - 1
                # Delta of height that will be filled with water
                bounded_height = (
                    min(height[current], height[st[-1]]) - height[top]
                )
                ans += distance * bounded_height
            st.append(current)
            current += 1

        return ans
