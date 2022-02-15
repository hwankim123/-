#include<iostream>
#include<memory.h>
using namespace std;

#define MAXN 100000

int N, T;
int score[2][MAXN];
int cache[2][MAXN];

int main() {
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		memset(cache, 0, sizeof(cache));
		cin >> N;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < N; j++) {
				cin >> score[i][j];
			}
		}
		for (int j = 0; j < N; j++) {
			for (int i = 0; i < 2; i++) {

				// 이부분 수정하고
				// x1,y1 ~ x2, y2까지 의 합을 저장하는 array 따로 선언
				int select_sum = score[i][j];
				if (j != 0) {
					select_sum += cache[(i + 1) % 2][j - 1];
				}
				int not_select_sum = 0;
				if (i == 0 && j != 0) {
					not_select_sum = cache[1][j - 1];
				}
				else if(i == 1 && j != 0){
					not_select_sum = cache[0][j];
				}
				cache[i][j] = (select_sum > not_select_sum) ? select_sum : not_select_sum;
			}
		}
	}
}