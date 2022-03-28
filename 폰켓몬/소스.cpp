#include <vector>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int n = nums.size();
    int check[200000] = { 0 };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 200000; j++) {
            if (nums[i] == j) {
                check[j]++;
            }
        }
    }

    for (int i = 0; i < 200000; i++) {
        if (check[i] != 0) {
            answer++;
        }
    }

    if (answer >= n / 2) {
        answer = n / 2;
    }
    else
        answer = answer;

    return answer;
}