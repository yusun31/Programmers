#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int first[] = { 1,2,3,4,5 };
    int second[] = { 2,1,2,3,2,4,2,5 };
    int third[] = { 3,3,1,1,2,2,4,4,5,5 };
    vector<int> ans(3);

    for (int i = 0; i < answers.size(); i++) {
        if (first[i % 5] == answers[i]) ans[0]++;
        if (second[i % 8] == answers[i]) ans[1]++;
        if (third[i % 10] == answers[i]) ans[2]++;
    }

    int max = 0;
    for (int i = 0; i < 3; i++) {
        if (ans[i] >= max) max = ans[i];
    }

    for (int i = 0; i < 3; i++) {
        if (ans[i] == max) {
            answer.push_back(i + 1);
        }
    }

    return answer;
}