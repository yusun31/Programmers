#include <iostream>
using namespace std;

int solution(int num) {
    int answer = 0;

    long long n = num;

    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
            answer++;
            cout << n << endl << answer << endl;
        }
        else {
            n = n * 3 + 1;
            answer++;
            cout << n << endl << answer << endl;
        }
    }

    if (answer <= 500)
        answer = answer;
    else
        answer = -1;

    return answer;
}