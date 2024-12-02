#include<bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n; int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int k; cin >> k;
	int ind = -1;
	int l = 0, r = n-1, mid;
	while(l <= r) {
		mid = (l + r) / 2;
		if (a[mid] == k) {
			ind = mid;
			break;
		}
		else if (a[mid] > k) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	if (ind != -1) {
		cout << ind << endl;
	}
	else cout << "Not found" << endl;
}