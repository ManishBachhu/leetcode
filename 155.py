class MinStack(object):

    def __init__(self):
        self.asc_stack = deque()
        self.num_stack = deque()

    def push(self, val):
        """
        Insert new element on top of stack.
        If new element is less than current_min, then add to asc_stack
        :type val: int
        :rtype: None
        """
        self.num_stack.append(val)
        if not self.asc_stack or self.asc_stack[-1] >= val:
            self.asc_stack.append(val)

    def pop(self):
        """
        if top is min, pop both. Else pop only num
        :rtype: None
        """
        if self.num_stack:
            val = self.num_stack[-1]
            self.num_stack.pop()
            if val == self.asc_stack[-1]:
                self.asc_stack.pop()

    def top(self):
        """
        :rtype: int
        """
        return self.num_stack[-1]

    def getMin(self):
        """
        :rtype: int
        """
        return self.asc_stack[-1]
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
