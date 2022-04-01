#include<iostream>
using namespace std;

#define MAXN 2000

int N, M;
int arr[MAXN];
bool cache[MAXN][MAXN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		cache[i][i] = true;
	}
	for (int dec = 1; dec < N; dec++) {
		for (int k = 0; k < N - dec; k++) {
			int i = k;
			int j = k + dec;

			if (i + 1 == j || i + 2 == j) {
				cache[i][j] = arr[i] == arr[j];
			}
			else {
				cache[i][j] = cache[i + 1][j - 1] && (arr[i] == arr[j]);
			}
		}
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int S, E; cin >> S >> E;
		cout << cache[S - 1][E - 1] << '\n';
	}
}