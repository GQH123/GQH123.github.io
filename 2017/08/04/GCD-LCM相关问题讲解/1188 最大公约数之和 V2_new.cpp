#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define maxn 5000005
#define LL long long int
using namespace std;
bool vis[maxn];
int cnt;
int p[maxn];
LL phi[maxn];
LL pre[maxn];

void init(){
    phi[1] = 1;
    for (int i = 2; i < maxn; i++){
        if (!vis[i]){
            p[cnt++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; j < cnt; j++){
            if (p[j] * i >= maxn) break;
            vis[p[j] * i] = 1;
            phi[i * p[j]] = phi[i] * (p[j] - 1);
            if (i % p[j] == 0){
                phi[i * p[j]] = phi[i] * p[j];
                break;
            }
        }
    }
    for (int i = 1; i < maxn; i++){
        for (int j = 1; i * j < maxn; j++){
            pre[i * j] += phi[i] * j;
        }
    }
    for (int i = 1; i < maxn; i++) pre[i] += pre[i - 1];
    for (int i = 1; i < maxn; i++) pre[i] -= (LL)i * (i + 1) >> 1;
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
        printf("%lld\n", pre[n]);
    }
    return 0;
}