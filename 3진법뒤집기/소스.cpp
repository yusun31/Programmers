#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> numbers(100);

    int por = n;
    int rest[100] = { 0 };
    int count = 0;
    while (1) {
        if (por == 0)
            break;

        else {
            for (int i = 0; por != 0; i++) {
                rest[i] = por % 3;
                por = por / 3;
                count++;
            }
        }
    }

    int k = count - 1;

    for (int i = 0; i < count; i++) {
        numbers[i] = rest[i];
        answer += numbers[i] * pow(3, k - i);
    }

    return answer;
}

int main()
{
    int n;
    int result = 0;

    cin >> n;

    result = solution(n);

    cout << result << endl;

    return 0;
}