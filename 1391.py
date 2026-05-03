class Solution:
    def hasValidPath(self, grid: List[List[int]]) -> bool:
        Rows = len(grid)
        Cols = len(grid[0])

        if Rows == 1 and Cols == 1:
            return True

        # returns di, dj for moving ahead 
        dirs = [
            (1000, 1000),  # illegal
            (0, 1),        # left
            (0, -1),       # right
            (1, 0),        # up
            (-1, 0)        # down
        ]

        # fsm represents old state -> new state
        # index is current state, value is new state
        # index of fsm is the street type
        fsm = [
            [0, 0, 0, 0, 0],
            [0, 1, 2, 0, 0],
            [0, 0, 0, 3, 4],
            [0, 3, 0, 0, 2],
            [0, 0, 3, 0, 1],
            [0, 4, 0, 2, 0],
            [0, 0, 4, 1, 0]
        ]

        def dfs(start: int) -> bool:
            i,j = 0, 0
            curr = start
            visited = set()
            while True:
                # print(f"{i}, {j}, {curr}")
                if (i, j) in visited:
                    return False

                if i < 0 or i >= Rows:
                    return False
                if j < 0 or j >= Cols:
                    return False

                if curr == 0:
                    return False

                if i == Rows - 1 and j == Cols - 1:
                    break

                next_dir = fsm[grid[i][j]][curr]
                di, dj = dirs[next_dir]
                visited.add((i, j))

                i += di
                j += dj
                curr = next_dir

            if fsm[grid[i][j]][curr]:
                return True
            else:
                return False

        for start in range(5):
            if start:
                if dfs(start):
                    return True

        return False

        
