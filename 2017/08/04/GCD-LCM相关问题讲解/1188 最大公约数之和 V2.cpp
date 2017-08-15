#include <cstdlib>
#include <cstdio>
#include <algorithm>
#define maxn 5000005
#define LL long long int
using namespace std;
bool vis[maxn];
int cnt;
int p[maxn];
int mu[maxn];
LL F[maxn];
void init(){
    mu[1] = 1;
    for (int i = 2; i < maxn; i++){
        if (!vis[i]){
            p[cnt++] = i;
            mu[i] = -1;
        }
        for (int j = 0; j < cnt; j++){
            if (p[j] * i >= maxn) break;
            vis[p[j] * i] = 1;
            mu[p[j] * i] = mu[i] * (-1);
            if (i % p[j] == 0){
                mu[i * p[j]] = 0;
                break;
            }
        }
    }
    for (int i = 1; i < maxn; i++){
        for (int j = 1; i * j < maxn; j++){
            F[i * j] += i * mu[j];
        }
    }
    for (int i = 1; i < maxn; i++) F[i] += F[i - 1];
}
void cal(int n){
    LL ans = 0;
    for (int i = 1; i <= n; i++){
        int next = n / (n / i);
        ans += (F[next] - F[i - 1]) * (n / i) * (n / i);
        i = next;
    }
    ans -= (LL) n * (n + 1) >> 1;
    ans >>= 1;
    printf("%lld\n", ans);
}
int main(){
    freopen("gcd2.in", "r", stdin);
    freopen("gcd2.out", "w", stdout);
    init();
    int T, a;
    scanf("%d", &T);
    while (T--){
        scanf("%d", &a);
        cal(a);
    }
    return 0;
}