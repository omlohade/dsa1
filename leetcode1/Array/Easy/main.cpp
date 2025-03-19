#include <bits/stdc++.h>
using namespace std;

long bitwiseRecurrence(long a, long b, long c, long n) {
    std::vector<long> v = {a, b, c};
    std::map<std::tuple<long, long, long>, long> m;
    m[{a, b, c}] = 0;
    for (long i = 3;; ++i) {
        long fn = (v[i - 1] | v[i - 2]) ^ v[i - 3];
        auto key = std::make_tuple(v[i - 1], v[i - 2], fn);
        if (m.count(key)) {
            long cycleStart = m[key], cycleLen = i - cycleStart;
            return v[n < cycleStart ? n : (n - cycleStart) % cycleLen + cycleStart];
        }
        m[key] = i;
        v.push_back(fn);
        if (i == n) return fn;
    }
    
}


int main() {
    long a, b, c, n;
    cin >> a >> b >> c >> n;

    cout << bitwiseRecurrence(a, b, c, n) << endl;

    return 0;
}
