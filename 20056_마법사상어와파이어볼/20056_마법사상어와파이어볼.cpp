#include <iostream>
#include <vector>
using namespace std;

struct Fireball { // 파이어볼
	int row;
	int col;
	int mess;
	int speed;
	int direction;
};

struct Cal { // 합쳐지는 파이어볼
	int sum_m;
	int sum_s;
	int sum_d;
	int count;
};

int main()
{
	int N, M, K;

	cin >> N >> M >> K;

	vector<Fireball> fireball;
	for (int i = 0; i < M; i++) { // input
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		Fireball fire = { r,c,m,s,d };
		fireball.push_back(fire);
		// cin >> fireball[i].row >> fireball[i].col >> fireball[i].mess >> fireball[i].speed >> fireball[i].direction;
	}

	vector<vector<Cal>> cal(N, vector<Cal>(N));
	int dir_r[8] = { -1,-1,0,1,1,1,0,-1 };
	int dir_c[8] = { 0,1,1,1,0,-1,-1,-1 };
	while (K != 0) {
		for (int i = 0; i < fireball.size(); i++) {
			// 파이어볼 이동
			fireball[i].row += dir_r[fireball[i].direction] * fireball[i].speed;
			fireball[i].col += dir_c[fireball[i].direction] * fireball[i].speed;
			fireball[i].row %= N;
			fireball[i].col %= N;
			if (fireball[i].row < 0) fireball[i].row += N;
			if (fireball[i].col < 0) fireball[i].col += N;
			// 이동한 자리에 질량합/속력합/방향/갯수 구하기
			cal[fireball[i].row][fireball[i].col].sum_m += fireball[i].mess;
			cal[fireball[i].row][fireball[i].col].sum_s += fireball[i].speed;
			cal[fireball[i].row][fireball[i].col].count++;
			if (fireball[i].direction % 2 == 0) cal[fireball[i].row][fireball[i].col].sum_d += 0;
			else cal[fireball[i].row][fireball[i].col].sum_d += 1;
		}
		int cnt = fireball.size();
		for (int i = 0; i < cnt; i++) {
			Fireball pushfire = fireball.back();
			fireball.pop_back();
			if (cal[pushfire.row][pushfire.col].count < 2) {
				fireball.insert(fireball.begin(), pushfire);
			}
		}
		// 이동완료 후 합쳐지는 파이어볼 계산
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (cal[i][j].count >= 2) {
					cal[i][j].sum_m /= 5;
					cal[i][j].sum_s /= cal[i][j].count;
					int dir;
					if (cal[i][j].sum_d % cal[i][j].count == 0) {
						dir = 0;
					}
					else {
						dir = 1;
					}
					if (cal[i][j].sum_m != 0) {
						for (int k = 0; k < 4; k++) {
							Fireball newfire = { i, j, cal[i][j].sum_m, cal[i][j].sum_s, dir };
							fireball.push_back(newfire);
							dir += 2;
						}
					}
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cal[i][j].sum_m = 0;
				cal[i][j].sum_s = 0;
				cal[i][j].sum_d = 0;
				cal[i][j].count = 0;
			}
		}
		K--;
	}

	int answer = 0;
	for (int i = 0; i < fireball.size(); i++) {
		answer += fireball[i].mess;
	}

	cout << answer << endl;

	return 0;
}