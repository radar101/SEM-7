#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<string> board, int n)
{
	int dupRow = row;
	int dupCol = col;
	while(row >= 0 and col >= 0)
	{
		if(board[row][col] == 'Q') return false;
		row--;
		col--;
	}

	row = dupRow;
	col = dupCol;

	while(col >= 0)
	{
		if(board[row][col] == 'Q') return false;
		col--;
	}

	col = dupCol;
	row = dupRow;
	while(row < n and col >= 0)
	{
		if(board[row][col] == 'Q') return false;
		row++;
		col--;
	}
	return true;
}


void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
{
	if(col == n) {
		ans.push_back(board);
		return;
	}

	for(int row = 0; row < n; row++)
	{
		if(isSafe(row, col, board, n))
		{
			board[row][col] = 'Q';
			solve(col + 1, board, ans, n);
			board[row][col] = '.';
		}
	}
}


void solve1(int col, vector<string> &board, vector<vector<string>> &ans,vector<int> &leftRow, vector<int> &lowerDiagonal, vector<int> &upperDiagonal, int n)
{
	if(col == n) {
		ans.push_back(board);
		return;
	}

	for(int row = 0; row < n; row++)
	{
		if(leftRow[row] == 0 and lowerDiagonal[row + col] == 0 and upperDiagonal[n-1 + col - row] == 0)
		{
			leftRow[row] = 1;
			lowerDiagonal[row + col] = 1;
			upperDiagonal[n-1+col - row] = 1;
			board[row][col] = 'Q';
			solve1(col + 1, board, ans, leftRow, lowerDiagonal, upperDiagonal, n);
			leftRow[row] = 0;
			lowerDiagonal[row + col] = 0;
			upperDiagonal[n-1+col - row] = 0;
			board[row][col] = '.';
		}
	}
}

vector<vector<string>> solveNQueen1(int n)
{
	vector<string> board(n);
	vector<vector<string>> ans;
	string s(n, '.');
	for(int i=0;i<n;i++)
	{
		board[i] = s;
	}
	vector<int> leftRow(n, 0), lowerDiagonal(2 * n - 1, 0), upperDiagonal(2 * n - 1, 0);
	solve1(0, board, ans, leftRow, lowerDiagonal,upperDiagonal, n);
	return ans;
}



vector<vector<string>> solveNQueen(int n)
{
	vector<string> board(n);
	vector<vector<string>> ans;
	string s(n, '.');
	for(int i=0;i<n;i++)
	{
		board[i] = s;
	}

	solve(0, board, ans, n);
	return ans;
}


int main()
{
	int n;
	cin>>n;
	vector<vector<string>> ans = solveNQueen1(n);

	for(auto i : ans)
	{
		for(auto s : i)
		{
			cout<<s<<endl;
		}
		cout<<endl;
	}
}