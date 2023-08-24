#include <iostream>
#include <vector>

using namespace std;

vector<int> f;

int get(int i) {
	int res = 0;
	while (i >= 0) {
		res += f[i];
		i = (i & (i + 1)) - 1;
	}
	return res;
}

void inc(int i, int x) {
	while (i < f.size()) {
		f[i] += x;
		i |= i + 1;
	}
}

int main()
{
	int n;
	cin >> n;

	vector<int> v(n);
	for (int& e : v)
		cin >> e;

	f.resize(n);
	f[0] = v[0];
	for (int i = 1; i < n; ++i)
		f[i] = f[i - 1] + v[i];
	for (int i = n - 1; i > 0; --i)
		if ((i & (i + 1)) != 0)
			f[i] -= f[(i & (i + 1)) - 1];

	char p;
	int i, x;
	while (1) {
		cin >> p;
		if (p == 'i') {
			cin >> i >> x;
			inc(i, x);
		}
		if (p == 's') {
			cin >> i;
			cout << get(i) << endl;
		}
	}
}
