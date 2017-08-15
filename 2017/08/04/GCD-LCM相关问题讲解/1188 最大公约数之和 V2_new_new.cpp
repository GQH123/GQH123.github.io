#include <cstdlib>
#include <cstdio>
#include <algorithm>
#define maxn 5000005
#define LL long long int
using namespace std;
bool vis[maxn];
int cnt;
int p[maxn];
int num[maxn];
LL F[maxn];
void init(){
    num[1] = 1;
    F[1] = 1;
    for (int i = 2; i < maxn; i++){
        if (!vis[i]){
            p[cnt++] = i;
            num[i] = 1;
            F[i] = (i << 1) - 1;
        }
        for (int j = 0; j < cnt; j++){
            if (i * p[j] >= maxn) break;
            vis[i * p[j]] = 1;
            num[i * p[j]] = i;
            F[i * p[j]] = F[i] * ((p[j] << 1) - 1);
            if (i % p[j] == 0){
                num[i * p[j]] = num[i];
                F[i * p[j]] = F[i] * p[j] + F[num[i]] * (i / num[i]) * (p[j] - 1);
                break;
            }
        }
    }
    for (int i = 1; i < maxn; i++) F[i] += F[i - 1];
    for (int i = 1; i < maxn; i++) F[i] -= (LL)i * (i + 1) >> 1;
}
int main(){
    freopen("gcd2.in", "r", stdin);
    freopen("gcd2.out", "w", stdout);
    init();
    int T;
    scanf("%d", &T);
    LL n;
    while (T--){
        scanf("%lld", &n);
        printf("%lld\n", F[n]);
    }
    return 0;
}