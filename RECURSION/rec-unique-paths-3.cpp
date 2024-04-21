#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>> &grid, int x, int y, int zeros)
{
	// grid size constraints and to confirm NOT on obstacle
	if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == -1)
	{
		return 0;
	}

	// destination node reached
	if (grid[x][y] == 2)
	{
		return (zeros == 0);
	}

	// else, follow this algorithm (current node => empty or src node)
	// mark current node as visited
	// reduce a zeros_left count by 1
	grid[x][y] = -1;
	zeros--;

	// compute for neighbouring 4-directions
	int ans = helper(grid, x + 1, y, zeros) + helper(grid, x, y + 1, zeros) + helper(grid, x - 1, y, zeros) + helper(grid, x, y - 1, zeros);

	// Backtrack
	zeros++;
	grid[x][y] = 0;

	// Return final answer value
	return ans;
}

int uniquePaths3(vector<vector<int>> &grid)
{
	pair<int, int> startPoint;
	int zeros = 1;

	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[0].size(); j++)
		{
			if (grid[i][j] == 1)
			{
				// storing startPoint value
				startPoint = {i, j};
			}
			else if (grid[i][j] == 0)
			{
				// setting zeroes counter value
				zeros++;
			}
		}
	}
	// Calculating function value, starting from startPoint(src node)
	return helper(grid, startPoint.first, startPoint.second, zeros);
}


int main()
{
	/*****************************
	 * NOTE: this code is copied from leetcode, no vidoe, smjh aa gya hai
	 * LEETCODE LINK: https://leetcode.com/problems/unique-paths-ii/
	 * VIDEO LINK: https://www.youtube.com/watch?v=XNKCkX_tHhM
	 * **************************************/
	vector<vector<int>> grid = {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 2, -1}};
	cout << uniquePaths3(grid);
}