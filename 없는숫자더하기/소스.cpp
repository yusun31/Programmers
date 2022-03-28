#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(vector<int> numbers) {
	int sum = 45;
	int array[10] = { 0,1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (numbers[i] == array[j])
				sum -= numbers[i];
		}
	}
	return sum;
}

int main()
{
	vector<int> numbers(10);

	for (int i = 0; i < 10; i++) {
		cin >> numbers[i];
	}

	int sum = solution(numbers);

	cout << sum;

	return 0;
}