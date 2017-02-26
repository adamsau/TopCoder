#define ALL(C) (C).begin(), (C).end()
#define forN(I, C) for(int I=0; I<int(C); ++I)
#define forEach(I, C) for(int I=0; I<int((C).size()); ++I)
#define forN1(I, C) for(int I=1; I<=int(C); ++I)
#define forEach1(I, C) for(int I=1; I<=int((C).size()); ++I)
#define PI 3.14159265358979323846
#define str(s) to_string(s)
#define INT(S) stoi(S)
#define PB(V) push_back(V)

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>

using namespace std;

typedef vector<string> VS;

char a[50][50];
int n, m;

void fill(int steps) {
	int vert = (steps & 1) ? 2 : 1;

	forN(i, vert) {
		forN(j, 49) {
			a[n + i + 1][j] = '#';
		}
	}
	n += vert;

	steps -= vert;

	int turn = 49 - (steps - 3) / 2;
	forN(i, turn) {
		a[n + 1][i] = '#';
	}
	n++;

	forN(i, 50) {
		if (i == turn) {
			continue;
		}
		a[n + 1][i] = '#';
	}
	n++;
	forN(i, turn) {
		a[n + 1][i] = '#';
	}
	n++;
}
VS solve(int k) {
	forN(i, 50) {
		forN(j, 50) {
			a[i][j] = '.';
		}
	}
	if (k < 50) {
		m = k;

		VS res;
		res.PB(string(a[0], m + 1));

		return res;
	}

	int steps = k;
	steps -= 49;
	int quot = steps / 102;
	int rem = steps % 102;

	m = 49;
	forN(i, quot) {
		fill(102);
	}

	if (rem >= 1 && rem <= 4) {
		forN1(i, rem) {
			forN(j, 49) {
				a[n + i][j] = '#';
			}
		}

		n += rem;
	}
	else if (rem > 4) {
		fill(rem);
	}

	VS res;
	forN(i, n + 1) {
		res.PB(string(a[i], 50));
	}

	return res;
}

//int main() {
//	int k = 967;
//	VS result = solve(k);
//	forEach(i, result) {
//		cout << result[i] << endl;
//	}
//
//	return 0;
//}

class MazeConstruct {
public:
	VS construct(int k) {
		return solve(k);
	}
};