#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    queue<int> q1, q2;
    int max = (queue1.size() + queue2.size()) * 2;
    long sum1 = 0, sum2 = 0;

    for (int i = 0; i < queue1.size(); i++) {
        q1.push(queue1[i]);
        sum1 += queue1[i];
    }
    for (int i = 0; i < queue2.size(); i++) {
        q2.push(queue2[i]);
        sum2 += queue2[i];
    }
    while (answer != max) {
        if (sum1 == sum2) {
            break;
        }
        else {
            int x;
            if (sum1 > sum2) {
                x = q1.front();
                q1.pop();
                q2.push(x);
                sum1 -= x;
                sum2 += x;
                answer++;
            }
            else {
                x = q2.front();
                q2.pop();
                q1.push(x);
                sum1 += x;
                sum2 -= x;
                answer++;
            }
        }
    }
    if (answer >= max) answer = -1;

    return answer;
}