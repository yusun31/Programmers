#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main()
{
	int N;

	cin >> N;

	string str[10] = { "" };
	vector<char> alpha = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	for (int i = 0; i < N; i++) {
		cin >> str[i];
	}

	int cnt = 0;
	map<char, int> new_alpha;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < str[i].length(); j++) {
			for (int k = 0; k < 26; k++) {
				if (str[i][j] == alpha[k]) {
					new_alpha[alpha[k]] = cnt;
					cnt++;
					alpha[k] = ' ';
				}
			}
		}
	}

	vector<int> num(new_alpha.size());
	int k = 0;
	int numsize = 10 - num.size();
	for (int i = 9; i >= numsize; i--) {
		num[k] = i;
		k++;
	}

	int no[10] = { 0 };
	int answer = 0;
	do {
		map<char, int>::iterator iter;
		int k = 0;
		int temp = 0;
		for (iter = new_alpha.begin(); iter != new_alpha.end(); iter++) {
			iter->second = num[k];
			k++;
		}
		for (int i = 0; i < N; i++) { // str 가져오려고
			for (int j = 0; j < str[i].length(); j++) { // str안에 있는 char값 하나씩 하려고
				no[i] *= 10;
				no[i] += new_alpha[str[i][j]];
			}
			temp += no[i];
			no[i] = 0;
		}
		if (temp > answer) answer = temp;
	} while (prev_permutation(num.begin(), num.end()));

	cout << answer << endl;

	return 0;
}