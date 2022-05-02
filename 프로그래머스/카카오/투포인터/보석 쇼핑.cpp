#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;
#define MAX 987654321

vector<int> solution(vector<string> gems) {
	if (gems.size() == 1) {
		return vector<int>(2, 1);
	}
	map<string, int> gemCount;
	gemCount.insert({ gems[0], 1 }); // init(처음 item은 이미 탐색했다고 가정)
	for (int i = 1; i < gems.size(); i++) {
		if (!gemCount.count(gems[i])) {
			gemCount.insert({ gems[i], 0 });
		}
	}
	if (gemCount.size() == 1) {
		return vector<int>(2, 1);
	}
	int min = MAX;
	int start = 0, end = 1;
	int lo = 0, hi = 1;
	int count = 1;
	while(hi < gems.size()){
		//cout << lo << ' ' << hi <<' ' << min << endl;
		if (gemCount[gems[hi]] == 0) {
			count++;
		}
		++gemCount[gems[hi]];
		if (count == gemCount.size()) {
			while (lo < hi) {
				if (gemCount[gems[lo]] == 1) {
					break;
				}
				--gemCount[gems[lo]];
				lo++;
			}
			if (min > hi - lo + 1) {
				min = hi - lo + 1;
				start = lo + 1;
				end = hi + 1;
			}
		}
		
		hi++;
	}
	//if (start - end + 1 > gems.size()) {
	//	end--;
	//}
	vector<int> result;
	result.push_back(start);
	result.push_back(end);
	return result;
}

int main() {
	vector<string> gems;
	string s;
	while (cin >> s) {
		if(s == "sibal") break;
		gems.push_back(s);

	}
	vector<int> sd = solution(gems);
	cout << sd[0] << ' ' << sd[1];
}