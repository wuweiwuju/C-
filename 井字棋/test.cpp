#define _CRT_SECURE_NO_WARNINGS 1
class Board {
public:
	bool checkWon(vector<vector<int> > board) {
		// write code here
		int count = 0;
		int num = 0;
		int flag = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (board[i][j] == 1)
				{
					count++;
					num = i;
					flag = j;
					if (num == i)
					{
						if (count == 3)
							return true;
					}
					if (flag == j)
					{
						if (count == 3)
							return true;
					}
					if (num == i + 1 && flag == j + 1)
					{
						num = i + 1;
						flag = j + 1;
						if (count == 3)
							return true;
					}
					if (num == i + 1 && flag == j - 1)
					{
						num = i + 1;
						flag = j - 1;
						if (count == 3)
							return true;
					}
				}
			}
		}
		return false;
	}
};