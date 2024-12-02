#include<bits/stdc++.h>
using namespace std;

int solve(int a[], int n) {
	if (n == 1) {
		return 0;
	}
	else if (n == 2) {
		return abs(a[1] - a[2]);
	}

	else{
		int choice1 = solve(a, n - 1) + abs(a[n] - a[n - 1]);
	int choice2 = solve(a, n - 2) + abs(a[n] - a[n - 2]);
	return min(choice1, choice2);
	}
}

int main() {
	int n; cin >> n;
	int a[n+1];
	for (int i = 1; i <= n; i++) cin >> a[i];
	cout << solve(a, n) << "\n";
	return 0;
}