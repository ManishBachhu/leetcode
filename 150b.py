class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        OPS = {'+', '-', '*', '/'}

        for c in tokens:
            # print(c)
            if c in OPS:
                a, b = stack.pop(), stack.pop()
                # print(a, b)

            if c == "+":
                stack.append(a + b)
            elif c == "-":
                stack.append(b - a)
            elif c == "*":
                stack.append(a * b)
            elif c == "/":
                stack.append(int(b / a))
            else:
                stack.append(int(c))

            # print(stack)

        return stack[-1]
