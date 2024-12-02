#include<bits/stdc++.h>
using namespace std;

vector < vector < int > > ans;
vector < int > v;
const int N = 1e5 + 7;
int vis[N];
int n;
void make() {

	if (v.size() == n) {
		ans.push_back(v);
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		v.push_back(i);
		vis[i] = true;
		make();
		vis[i] = false;
		v.pop_back();
	}
}

int main() {
	cin >> n;
	make();

	for (auto el: ans) {
		for (int e: el) cout << e;
		cout << "\n";
	}
	return 0;
}