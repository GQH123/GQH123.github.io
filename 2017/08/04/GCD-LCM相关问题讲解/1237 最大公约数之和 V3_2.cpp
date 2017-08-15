#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#define LL long long int 
#define maxn 5000005
#define M 1000000007
using namespace std;
int p[maxn];
bool vis[maxn];
int cnt;
int bound;
int phi[maxn];
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
map<LL, LL> save;
LL dyh(LL x){
    if (x < bound) return phi[x];
    if (save.count(x)) return save[x];
    LL ans = x % M * ((x + 1) % M) % M * ((M + 1) >> 1) % M;
    for (LL i = 2; i <= x; i++){///////////////Serious Mistake!!!
        LL next = x / (x / i);
        ans = (M + ans - dyh(x / i) * ((next - i + 1) % M) % M) % M;
        i = next;
    }
    return save[x] = ans;
}
void work(LL n){
    LL ans = 0;
    for (LL i = 1; i <= n; i++){
        LL next = n / (n / i);
        ans = (ans + (n / i) % M * ((n / i) % M) % M * (M + (dyh(next) - dyh(i - 1)) % M) % M) % M;
        i = next;
    }
    /*LL rec = n % M * ((n + 1) % M) % M * ((M + 1) >> 1) % M; 
    ans = (M + ans - rec) % M;
    ans = ans * 2 % M;
    ans = (ans + rec) % M;*/
    printf("%lld", ans);
}
int main(){
    freopen("gcd3.in", "r", stdin);
    freopen("gcd3.out" ,"w", stdout);
    LL n;
    scanf("%lld", &n);
    bound = (int) pow(n, 2.0 / 3) + 1;
    init();
    work(n);
    return 0;
}