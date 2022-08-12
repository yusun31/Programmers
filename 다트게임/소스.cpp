#include <string>
#include <cmath>
#include <vector>
using namespace std;

int solution(string dartResult) {
    int answer = 0;

    vector<int> num(3, 0);
    char bonus[3] = { ' ' };
    int k = 0, l = 0;

    for (int i = 0; i < dartResult.length(); i++) {
        if (dartResult[i] - '0' < 10 && dartResult[i] - '0' > 0 && dartResult[i + 1] != '0') {
            num[k] = dartResult[i] - '0';
            k++;
        }
        else if (dartResult[i] == '1' && dartResult[i + 1] == '0') {
            num[k] = 10;
            k++;
        }
        else if (dartResult[i] == '0' && dartResult[i - 1] != '1') {
            num[k] = 0;
            k++;
        }

        if (dartResult[i] == 'S') {
            bonus[l] = dartResult[i];
            l++;
        }
        else if (dartResult[i] == 'D') {
            bonus[l] = dartResult[i];
            l++;
        }
        else if (dartResult[i] == 'T') {
            bonus[l] = dartResult[i];
            l++;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (bonus[i] == 'S')
            num[i] = num[i];
        else if (bonus[i] == 'D')
            num[i] = pow(num[i], 2);
        else
            num[i] = pow(num[i], 3);
    }

    for (int i = 0; i < dartResult.length(); i++) {
        if (dartResult[i] == '*') {
            if (i == 2) {
                num[0] *= 2;
            }
            else if (i == 4 || i == 5) {
                num[0] *= 2;
                num[1] *= 2;
            }
            else {
                num[1] *= 2;
                num[2] *= 2;
            }
        }
        if (dartResult[i] == '#') {
            if (i == 2) {
                num[0] *= -1;
            }
            else if (i == 4 || i == 5) {
                num[1] *= -1;
            }
            else {
                num[2] *= -1;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        answer += num[i];
    }

    return answer;
}