#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <map>
#include <cmath>
#define M 1000000007
#define maxn 5000005
#define LL long long int
using namespace std;
bool vis[maxn];
int p[maxn];
int cnt;
int phi[maxn];
map<LL, LL> save;
int bound;
LL n;
void init(){
    phi[1] = 1;
    for (int i = 2; i < bound; i++){
        if (!vis[i]){
            p[cnt++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; j < cnt; j++){
            if (i * p[j] >= bound) break;
            vis[i * p[j]] = 1;
            phi[i * p[j]] = phi[i] * (p[j] - 1);
            if (i % p[j] == 0){
                phi[i * p[j]] = phi[i] * p[j];
                break;
            }
        }
    }
    for (int i = 1; i < bound; i++) phi[i] = (phi[i - 1] + phi[i]) % M;
}
LL dyh_sieve(LL x){
    if (x < bound) return phi[x];
    if (save.count(x)) return save[x];
    LL ans = (x & 1) ? (x % M) * (((x + 1) >> 1) % M) % M : ((x >> 1) % M) * ((x + 1) % M) % M;
    for (LL i = 2; i <= x; i++){
        LL next = x / (x / i);
        ans = (ans + M - dyh_sieve(x / i) * (next - i + 1) % M) % M;
        i = next;
    }
    return save[x] = ans;
}
int main(){
    freopen("phi.in", "r", stdin);
    freopen("phi.out", "w", stdout);
    scanf("%lld", &n);
    bound = pow(n, 2.0 / 3) + 1;
    init();
    printf("%lld", dyh_sieve(n));
    return 0;
}