//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//typedef vector<vector<vector<int>>> vec3d;
//
//int f(vec3d& data, int n, int l, int r)
//{
//    if (l < 1 || r < 1 || n <= 0)
//    {
//        return 0;
//    }
//
//    if (n == 1)
//    {
//        return (l == r == 1) ? 1 : 0;
//    }
//
//    if (data[n][l][r] != -1)
//    {
//        return data[n][l][r];
//    }
//
//    data[n][l][r] = f(data, n - 1, l - 1, r) + f(data, n - 1, l, r - 1) + (n - 2) * f(data, n - 1, l, r);
//
//    return data[n][l][r];
//}
//
//void solve(const char* inputPath, const char* outputPath, int cnt)
//{
//    freopen(inputPath, "r", stdin);
//    freopen(outputPath, "w", stdout);
//
//    while (cnt--)
//    {
//        int n, l, r;
//
//        cin >> n >> l >> r;
//        cout << n << l << r;
//
//        vec3d data(1000, vector<vector<int>>(1000, vector<int>(1000)));
//
//        int result = f(data, n, l, r);
//
//        cout << result << endl;
//    }
//}
//
//int main()
//{
//    int cnt = 3;
//
//    solve("input.txt", "output.txt", cnt);
//
//    return 0;
//}

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<vector<int>>> vec3d;

int f(vec3d& dp, int n, int l, int r)
{

	if (n == 1) return (l == 1 && r == 1) ? 1 : 0;

	if ((l < 1) || (r < 1)) return 0;

	if (dp[n][l][r] != -1) return dp[n][l][r];

	dp[n][l][r] = f(dp, n - 1, l - 1, r) + f(dp, n - 1, l, r - 1) + (n - 2) * f(dp, n - 1, l, r);

	return dp[n][l][r];

}

void solve(const char* inputPath, const char* outputPath, int cnt)
{
	freopen(inputPath, "r", stdin);
	freopen(outputPath, "w", stdout);

	while (cnt--)
	{
		int n, l, r;

		cin >> n >> l >> r;

		vec3d data(100, vector<vector<int>>(100, vector<int>(100)));

		for (int i = 0; i < data.size(); i++)
		{
			for (int j = 0; j < data[i].size(); j++)
			{
				for (int q = 0; q < data[i][j].size(); q++)
				{
					data[i][j][q] = -1;
				}
			}
		}

		int result = f(data, n, l, r);

		cout << result << endl;
	}
}

int main()
{
	int cnt = 3;

	solve("input.txt", "output.txt", cnt);

	return 0;
}