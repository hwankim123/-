#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool checkSymbol(char c) {
	string s = "-_.~!@#$%^&*()=+[{]}:?,<>/";
	int i;
	bool flag = true;
	for (i = 0; i < s.length(); i++) {
		if (c == s[i] && i > 2) {
			flag = false;
			break;
		}
		else if (c == s[i] && i <= 2) {
			break;
		}
	}
	return flag;
}

string solution(string new_id) {
	cout << "#1" << endl;
	for (int i = 0; i < new_id.length(); i++) {
		if (new_id[i] >= 65 && new_id[i] <= 90) {
			new_id[i] += 32;
		}
	}
	cout << new_id << endl;
	cout << "#2" << endl;
	int i = 0;
	while (i < new_id.length()) {
		if (!checkSymbol(new_id[i])) {
			new_id.replace(i, 1, "");
		}
		else i++;
	}

	cout << new_id << endl;
	cout << "#3" << endl;
	i = 0;
	int count = 0;
	while (i < new_id.length()) {
		if (new_id[i] == '.') {
			count++;
			if (count >= 2) {
				new_id.replace(i, 1, "");
				count--;
			}
			else {
				i++;
			}
		}
		else {
			count = 0;
			i++;
		}
	}

	cout << new_id << endl;
	cout << "#4" << endl;
	if (new_id[0] == '.') {
		new_id.replace(0, 1, "");
	}
	if (new_id[new_id.length() - 1] == '.') {
		new_id.replace(new_id.length() - 1, 1, "");
	}

	cout << new_id << endl;
	cout << "#5 6 7" << endl;
	if (new_id.length() == 0) {
		new_id = "a";
	}
	else if (new_id.length() >= 16) {
		if (new_id[14] == '.') {
			new_id.resize(14);
		}
		else {
			new_id.resize(15);
		}
	}
	else if (new_id.length() <= 2) {
		i = new_id.length();
		char c = new_id[new_id.length() - 1];
		while (i < 3) {
			new_id += c;
			i++;
		}
	}
	return new_id;
}

int main() {
	string s;
	cin >> s;
	cout << endl << solution(s);
}