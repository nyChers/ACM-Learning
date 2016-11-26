#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int p, q;
	cin >> p >> q;
	string t;
	bool flag = false;
	for (int i = p; i <= q; i++) {
		if (i == 1) {
			cout << 1 << " ";
			continue;
		}
		long long kn = pow(i, 2);
		t = to_string(kn);
		int n = t.length();
		int d = to_string(i).length();
		int dl = n - d;
		if (dl <= 0)
			continue;
		int r = stol(t.substr(dl), NULL, 10);
		int l = stol(t.substr(0, dl), NULL, 10);
		if (l + r == i) {
			flag = true;
			cout << i << " ";
		}
	}
	if (!flag)
		cout << "INVALID RANGE";
	cout << endl;
	return 0;
}
