class Solution:
    def getNextDelta(self, direction) -> int:
        order = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        currIndex = order.index(direction)
        return order[(currIndex + 1) % 4]

    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        M, N = len(matrix[0]), len(matrix)
        visited = [[False] * M for _ in range(N)]
        i, j, countVisited = 0, 0, 0
        di, dj = (0, 1)
        out = []

        while countVisited < M * N:
            out.append(matrix[i][j])
            visited[i][j] = True
            countVisited += 1

            if i + di >= N or j + dj >= M or i + di < 0 or j + dj < 0 or \
                visited[i + di][j + dj]:
                    di, dj = self.getNextDelta((di, dj))

            i += di
            j += dj

        return out
