#include <iostream>
using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;

    for (int i = 1; i <= count; i++) {
        answer += price * i;
    }
    if (answer > money) {
        answer -= money;
    }
    else
        answer = 0;

    return answer;
}

int main()
{
    int p, m, c;
    long long result;

    cin >> p >> m >> c;

    result = solution(p, m, c);

    cout << result << endl;

    return 0;
}