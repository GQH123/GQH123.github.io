#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <map>
#include <cmath>
#define maxn 5000005
#define LL long long int
using namespace std;
bool vis[maxn];
int prime[maxn];
int mu[maxn];
int cnt;
LL a, b;
map<LL, LL> save;
void init(int bound){
    mu[1] = 1;
    for (int i = 2; i < bound; i++){
        if (!vis[i]){
            prime[cnt++] = i;
            mu[i] = -1;
        }
        for (int j = 0; j < cnt; j++){
            if (i * prime[j] >= bound) break;
            vis[i * prime[j]] = 1;
            mu[i * prime[j]] = mu[i] * (-1);
            if (i % prime[j] == 0){
                mu[i * prime[j]] = 0;
                break;
            }
        }
    }
    for (int i = 1; i < bound; i++) mu[i] += mu[i - 1];
}
int bound;
LL dyh_sieve(LL x){
    if (x < bound) return mu[x];
    if (save.count(x)) return save[x];
    LL ans = 1;
    for (LL i = 2; i <= x; i++){
        LL next = x / (x / i);
        ans -= dyh_sieve(x / i) * (next - i + 1);
        i = next;
    }
    return save[x] = ans;
}
int main(){
    freopen("mobius.in", "r" ,stdin);
    freopen("mobius.out", "w", stdout);
    scanf("%lld%lld", &a, &b);
    init(bound = (int)pow(b, 2.0 / 3) + 1);
    printf("%lld", dyh_sieve(b) - dyh_sieve(a - 1));
    return 0;
}