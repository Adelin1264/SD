#include <fstream>
#include <queue>
#include <vector>
 
using namespace std;
 
#define Inf 0x3f3f3f3f
 
ifstream cin("divquery.in");
ofstream cout("divquery.out");
 
const int Max_N = 100005;
const int LOG = 17;
int a[Max_N + 1];
int m[Max_N + 1][LOG + 1];
int n, q;
int l, r;
 
int cmmdc(int a, int b) {
    if (b == 0)
        return a;
    else
        return cmmdc(b, a % b);
}
 
int query(int l, int r) {
    int length = r - l + 1;
    int k = 0;
    while ((1 << (k + 1)) <= length)
        k++;
 
    return cmmdc(m[l][k], m[r - (1 << k) + 1][k]);
}
 
int main() {
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        m[i][0] = a[i];
    }
 
    for (int k = 1; k < LOG; ++k) {
        for (int i = 0; i + (1 << k) - 1 < n; ++i) {
            m[i][k] = cmmdc(m[i][k - 1], m[i + (1 << (k - 1))][k - 1]);
        }
    }
 
    while (q >= 1) {
        cin >> l >> r;
        cout << query(l - 1, r - 1) << '\n';
        q--;
    }
 
    return 0;
}
 