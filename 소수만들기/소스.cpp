#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;

    sort(nums.begin(), nums.end());
    int r = 3;
    vector<bool> temp(nums.size(), false);
    for (int i = 0; i < r; i++)
        temp[i] = true;

    do {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (temp[i]) {
                sum += nums[i];
            }
        }
        int cnt = 0;
        for (int i = 1; i <= sum; i++) {
            if (sum % i == 0) {
                cnt++;
            }
        }
        if (cnt <= 2) {
            answer++;
        }
    } while (prev_permutation(temp.begin(), temp.end()));

    return answer;
}