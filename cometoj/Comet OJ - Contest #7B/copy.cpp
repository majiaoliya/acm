#include <bits/stdc++.h>
using namespace std;

using LL = long long;

namespace _buff {

const size_t BUFF = 1 << 19;
char ibuf[BUFF], *ib = ibuf, *ie = ibuf;
char getc() {
    if (ib == ie) {
        ib = ibuf;
        ie = ibuf + fread(ibuf, 1, BUFF, stdin);
    }
    return ib == ie ? -1 : *ib++;
}

}

LL read() {
    using namespace _buff;
    LL ret = 0;
    bool pos = true;
    char c = getc();
    for (; (c < '0' || c > '9') && c != '-'; c = getc()) {
        assert(~c);
    }
    if (c == '-') {
        pos = false;
        c = getc();
    }
    for (; c >= '0' && c <= '9'; c = getc()) {
        ret = (ret << 3) + (ret << 1) + (c ^ 48);
    }
    return pos ? ret : -ret;
}

int main() {
	freopen("test", "r", stdin);
    int t = read();
    while (t--) {
        int l = read(), r = read();
        if (l == r) {
            printf("%d %d %d %d\n", r, r, r, r);
        } else {
            printf("%lld %d %d %d\n", (LL) r * (r - 1), l, r, 1);
        }
    }
    return 0;
}
