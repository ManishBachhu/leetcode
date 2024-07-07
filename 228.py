def append_to_ans(ans, l, r):
    if l is None:
        return
    if l == r:
        ans.append(str(l))
    else:
        ans.append(str(l) + "->" + str(r))

class Solution(object):
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        ans  = []
        # iterate through the array
        # init l, r; (l -> first of range, r -> current last of range)
        # for every new element, check if it is +1 of r
        # if yes, update r
        # else, add to "{l}->{r}" to ans and update l, r to new element
        # if l == r, add only "l" to ans
        # finally, add "{l}->{r}" or "{l}" to ans
        l = r = None
        for n in nums:
            if l is None:
                l = r = n
            elif n == r + 1:
                r = n
            else:
                append_to_ans(ans, l, r)
                l = r = n
        append_to_ans(ans, l, r)
        return ans