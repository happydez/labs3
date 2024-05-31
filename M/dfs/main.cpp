#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

// Классический поиск в глубину (на графе)
void dfs(vector<vector<int>>& graph, vector<bool>& visited, int i) {
	visited[i] = true;

	for (int j = 0; j < graph[i].size(); j++) {
		if (graph[i][j] == 1 && !visited[j]) {
			dfs(graph, visited, j);
		}
	}

}

void solve(const char* inputPath, const char* outputPath, int cnt) {

    freopen(inputPath, "r", stdin);
    freopen(outputPath, "w", stdout);

    // Вводим 3 раза разные входные данные
    while (cnt-- > 0) {
        int n;
        cin >> n;

        // Вводим матрицу с файла
        vector<vector<int>> graph(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> graph[i][j];
            }
        }

        // Поиск в глубину (ищем компоненты связности
        // если k = 1, то все могут подружиться
        int k = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                k++;
                dfs(graph, visited, i);
            }
        }

        // Выводим ответ
        if (k == 1) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}

int main() {

	int cnt = 3;

	solve("input.txt", "output.txt", cnt);

	return 0;
}