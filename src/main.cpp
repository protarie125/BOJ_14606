#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;

vi memo;
int solve(int n) {
	if (memo[n] < 0) {
		auto ans = int{ 0 };

		const auto& toCheck = n / 2;
		for (int i = 1; i <= toCheck; ++i) {
			const auto& p = i * (n - i) + solve(i) + solve(n - i);

			if (ans < p) {
				ans = p;
			}
		}

		memo[n] = ans;
	}

	return memo[n];
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	cin >> n;
	if (1 == n) {
		cout << 0;
		return 0;
	}

	memo = vi(n + 1, -1);
	memo[1] = 0;

	cout << solve(n);

	return 0;
}