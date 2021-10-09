#include <unordered_map>
#include <stdio.h>

using namespace std;

int main() {
	int w, h, l;
	scanf("%d %d %d", &w, &h, &l);

	int temp;
	int sum = 0;
	for (int x = 1; x < l; x++)
		sum += sqrt(pow(l, 2) - pow(x, 2));
	temp = sum;
	sum *= 3;
	sum += 2 * l;

	if (w < l) sum += l - w;
	if (h < l) sum += l - h;

	if (w + h >= l) {
		int nl = l - w;
		if (nl > 0) {
			for (int x = 1; x < nl; x++)
				sum += sqrt(pow(nl, 2) - pow(x, 2));
		}

		nl = l - h;
		if (nl > 0) {
			for (int x = 1; x < nl; x++)
				sum += sqrt(pow(nl, 2) - pow(x, 2));
		}
	}

	else {
		int sub = 0;
		for (int x = 1; x < l; x++) {
			int y = sqrt(pow(l, 2) - pow(x, 2));
			int a = sqrt(pow(l - h, 2) - pow(x, 2)) + h;
			int b = sqrt(pow(l - w, 2) - pow(x - w, 2));
			int y1 = max(a, b);
			sub += y - y1;
		}
		sub += w * h;

		temp -= sub;
		sum += temp;
	}

	printf("%d\n", sum);

	return 0;
}
