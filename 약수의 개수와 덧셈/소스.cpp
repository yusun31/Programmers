#include <iostream>
#include <vector>
using namespace std;

int solution(int left, int right) {
    int answer = 0;

    vector<int> temp(right - left + 1);
    int divisor[] = {};
    for (int i = left; i <= right; i++) {
        int count = 0;
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) {
                divisor[count++] = j;
            }
        }
        if (count % 2 == 0) {
            answer += divisor[i - left];
        }
        else {
            answer -= divisor[i - left];
        }
    }

    return answer;
}