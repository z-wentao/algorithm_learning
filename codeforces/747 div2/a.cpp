#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
	int T;
	cin >> T;
	while (T -- ) {
		ll n;
		scanf("%lld", &n);
		if (n == 0) printf("-1 1\n");
		if (n > 0) printf("%lld %lld\n", -n + 1, n);
		else printf("%lld %lld\n", -n, n - 1);
	}
	return 0;
}
