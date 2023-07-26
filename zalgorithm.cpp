#include <string>
using namespace std;

int zAlgorithm(string s, string p, int n, int m) {
    if (m > n) return 0;
    string concat = p + "#" + s;
    int len = m + n + 1;

    int Z[len] = {0};
    int count = 0;
    for (int i = 1, l = 0, r = 0; i < len; ++i) {
        if (i <= r)
            Z[i] = min(r - i + 1, Z[i - l]);
        while (i + Z[i] < len && concat[Z[i]] == concat[i + Z[i]])
            ++Z[i];
        if (i + Z[i] - 1 > r) {
            l = i;
            r = i + Z[i] - 1;
        }

        if (Z[i] == m)
            ++count;
    }

    return count;
}
