#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define maxn 100005
#define M 1000000007
#define LL long long int
using namespace std;
int p[maxn];
int cnt;
bool vis[maxn];
void init(){
    for (int i = 2; i < maxn; i++){
        if (!vis[i]) p[cnt++] = i; 
        for (int j = 0; j < cnt; j++){
            if (i * p[j] >= maxn) break;
            vis[i * p[j]] = 1;
            if (i % p[j] == 0) break;
        }
    }
}
void work(int n){
    LL ans = 1;
    LL now = 1;
    int t = n;
    int con = (int) sqrt(n);
    for (int i = 2; i <= con; i++){
        if (!vis[i] && n % i == 0){
            while (n % i == 0){
                now *= i;
                n /= i;
            }
            now *= now;
            now = (now - 1) / (i + 1);
            now *= i;
            ans = ans * (now + 1) % M;
            now = 1;
            con = (int) sqrt(n);
        }
    }
    if (n != 1) ans = ans * (((LL)n * n - n + 1) % M) % M;
    ans = (ans + 1) * t % M;
    ans = ans * ((M + 1) >> 1) % M;
    printf("%lld\n", ans);
}
int main(){
    freopen("sum2.in", "r", stdin);
    freopen("sum2.out", "w", stdout);
    init();
    int T, n;
    scanf("%d", &T);
    while (T--){
        scanf("%d", &n);
        work(n);
    }
    return 0;
}