#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+7;
int a[N];

void merge(int l , int r, int mid) {
	int left_size = mid - l + 1;
	int right_size = r - mid;
	int left[left_size + 1], right[right_size + 1];
	for (int i = l, j = 0; i <= mid; i++, j++) {
		left[j] = a[i];
	} 
	for (int i = mid + 1, j = 0; i <= r; i++, j++) {
		right[j] = a[i];
	}
	left[left_size] = INT_MIN;
	right[right_size] = INT_MIN;

	int lp = 0, rp = 0;
	for (int i = l; i <= r; i++) {
		if (left[lp] > right[rp]) {
			a[i] = left[lp++];
		} else {
			a[i] = right[rp++];
		}
	}
}

void Sort(int l, int r) {
	if (l == r) {
		return;
	}
	int mid = (l + r) / 2;
	Sort(l, mid);
	Sort(mid + 1, r);
	merge(l, r, mid);
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	Sort(0, n-1);
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
}