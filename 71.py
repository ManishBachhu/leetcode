class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        dir_list = path.split('/')
        print(dir_list)
        dir_stack = []

        for dir in dir_list:
            if dir == "." or dir == "":
                continue
            elif (dir == ".."):
                if dir_stack:
                    dir_stack.pop()
            else:
                dir_stack.append(dir)

        if not dir_stack:
            return "/"

        return "/" + "/".join(dir_stack)
            
