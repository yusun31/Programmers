#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int student[30] = { 0 };
    int answer = 0;

    for (int i = 0; i < n; i++) {
        student[i] = 1;
    }

    sort(lost.begin(), lost.end());
    for (int i = 0; i < lost.size(); i++) {
        student[lost[i] - 1]--;
    }

    sort(reserve.begin(), reserve.end());
    for (int i = 0; i < reserve.size(); i++) {
        student[reserve[i] - 1]++;
    }

    for (int i = 0; i < n; i++) {
        if (student[i] == 0) {
            if (student[i - 1] > 1) {
                student[i]++;
                student[i - 1]--;
            }
            else if (student[i + 1] > 1) {
                student[i]++;
                student[i + 1]--;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (student[i] != 0)
            answer++;
    }

    return answer;
}