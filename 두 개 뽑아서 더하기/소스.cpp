#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> numbers) {
    int n = 0;
    for (int i = 0; i < numbers.size(); i++) {
        n += i;
    }
    vector<int> answer(n);

    int count = 0;
    for (int i = 0; i < numbers.size() - 1; i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            answer[count] = numbers[i] + numbers[j];
            count++;
        }
    }

    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());

    return answer;
}