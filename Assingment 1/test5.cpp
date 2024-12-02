#include<bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n; int a[n + 1];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int m; cin >> m; int b[m + 1];
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	a[n] = INT_MIN;
	b[m] = INT_MAX;
	int ans[n + m];
	int lp = 0, rp = 0;
	for (int i = 0; i < n + m; i++) {
		if (a[lp] > b[rp]) {
			ans[i] = a[lp++];
		} else {
			ans[i] = b[rp++];
		}
	}
	for (int i = 0; i < n + m; i++) {
		cout << ans[i] << ' ';
	}
} 