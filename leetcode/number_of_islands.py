#!/usr/bin/env python

# https://leetcode.com/problems/number-of-islands/

from collections import deque

class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        islands_count = 0
        def _dfs(i, j, mark):
            if grid[i][j] != "1":
                return
            grid[i][j] = mark
            if (i > 0):
                _dfs(i - 1, j, mark)
            if (i < len(grid) - 1):
                _dfs(i + 1, j, mark)
            if (j > 0):
                _dfs(i, j - 1, mark)
            if (j < len(grid[0]) - 1):
                _dfs(i, j + 1, mark)
        for i in range(0, len(grid)):
            for j in range(0, len(grid[0])):
                if grid[i][j] == "1":
                    islands_count += 1
                    _dfs(i, j, islands_count)
        return islands_count

def test():
    s = Solution()
    grid = [
        ["1","1","1","1","0"],
        ["1","1","0","1","0"],
        ["1","1","0","0","0"],
        ["0","0","0","0","0"]
    ]
    assert(s.numIslands(grid) == 1)

    grid = [
        ["1","1","0","0","0"],
        ["1","1","0","0","0"],
        ["0","0","1","0","0"],
        ["0","0","0","1","1"]
    ]
    assert(s.numIslands(grid) == 3)

if __name__ == '__main__':
    test()