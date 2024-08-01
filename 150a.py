class Solution(object):
    def doOperation(self, op_stack):
        op, num_stack = op_stack.pop()
        a, b = num_stack[-2], num_stack[-1]

        res = self.applyOperator(a, b, op)
        if op_stack:
            op_stack[-1][1].append(res)
        else:
            op_stack.append(("", [res]))


    def applyOperator(self, a, b, op) -> int:
        res = 0
        # print(f"{b} {op} {a}")
        match op:
            case "+": res = a + b
            case "-": res = b - a
            case "*": res = a * b
            case "/": res = int(b / a)
        return res

    def evalRPN(self, tokens) -> int:
        """
        Read from right to left. Add item to respective stacks.
        If two num are in sequence pop two num and one op and store result back
        in num_stack
        :type tokens: List[str]
        :rtype: int
        """
        op_stack = deque()

        for item in reversed(tokens):
            if item in op_set:
                op_stack.append((item, []))
            else:
                if op_stack:
                    op_stack[-1][1].append(int(item))
                else:
                    op_stack.append(("", [int(item)]))

            # check if op needs to be done
            while len(op_stack[-1][1]) == 2:
                self.doOperation(op_stack)

            # print(op_stack)

        return op_stack[0][1][0]
