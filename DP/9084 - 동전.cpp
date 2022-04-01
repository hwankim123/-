#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAXM 10001

int T, N, M;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cin >> N;
		vector<int> coin(N, 0);
		vector<vector<int> >cache = vector<vector<int> >(N, vector<int>(MAXM, 0));
		for (int i = 0; i < N; i++) {
			cin >> coin[i];
		}
		cin >> M;
		sort(coin.begin(), coin.end());
		for (int i = 0; i < N; i++) {
			cache[i][coin[i]] = 1;
		}
		for (int j = coin[0]; j <= M; j++){
			for (int i = 0; i < N; i++) {
				int maxCache = 0;
				if (j > coin[i]) {
					maxCache = cache[0][j - coin[i]];
					for (int k = 0; k <= i; k++) {
						if (maxCache < cache[k][j - coin[i]]) {
							maxCache = cache[k][j - coin[i]];
						}
					}
				}
				if (i == 0) {
					cache[i][j] += maxCache;
				}
				else {
					cache[i][j] += maxCache + cache[i - 1][j];
				}
			}
		}
		cout << cache[N - 1][M] << '\n';
	}
}