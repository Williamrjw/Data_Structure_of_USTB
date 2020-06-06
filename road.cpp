#include <iostream>
using namespace std;
const int INF = 2147483640;
int getNo(int i, int j) {
	if (i == j) { 
		cout << "i=j" << endl; 
		exit(1); }
	if (i > j) { int tmp = i; i = j; j = tmp; }
	return (j - 2)*(j - 1) / 2 + i - 1;
};//得到上三角矩阵的对应节省空间的数组序号
int main() {
	int n, m, c;
	cin >> n >> m >> c;
	int no1, no2;
	int *graph = new int[(n*(n - 1) / 2)];
	int *dist = new int[n + 1];
	bool *s = new bool[n + 1];
	for (int i = 0; i < n + 1; i++) {
		dist[i] = INF;
		s[i] = 0;
	}
	dist[c] = 0;
	for (int i = 0; i < (n*(n - 1) / 2); i++) {
		graph[i] = INF;
	}
	for (int i = 0; i < m; i++) {
		cin >> no1 >> no2;
		graph[getNo(no1, no2)] = 1;
	}
	int count = 0, j, i, x;
	while (count <= n - 1) {
		m = INF, i = 0;
		for (x = 1; x < n + 1; x++) {
			if (0 == s[x] && dist[x] < m) {
				i = x; m = dist[x];
			}
		}
		if (INF == m)break;
		s[i] = 1;
		for (j = 1; j < n + 1; j++) {
			if (i == j || 1==s[j])continue;
			if (dist[j] > dist[i] + graph[getNo(i, j)] && INF!=graph[getNo(i,j)])
				dist[j] = dist[i] + graph[getNo(i, j)];
		}
		count++;
	}
	for (int i = 1; i <= n; i++) {
		if (i != c)
			cout << dist[i] << endl;
		else
			cout << 0 << endl;
	}
	/*cout<<"Go your mother. Stay at your home and keep the social distance."<<endl;*/
	return 0;
}