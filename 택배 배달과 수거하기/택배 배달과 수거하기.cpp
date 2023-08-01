#include <string>
#include <vector>
using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;

    long long next_deliver = 0;
    long long next_pickup = 0;

    for (int i = n - 1; i >= 0; i--) {
        int count = 0;

        deliveries[i] += next_deliver;
        pickups[i] += next_pickup;

        while (deliveries[i] > 0 || pickups[i] > 0) {
            deliveries[i] -= cap;
            pickups[i] -= cap;
            count++;
        }

        next_deliver = deliveries[i];
        next_pickup = pickups[i];

        if (count != 0) {
            answer += 2 * (i + 1) * count;
        }
    }

    return answer;
}