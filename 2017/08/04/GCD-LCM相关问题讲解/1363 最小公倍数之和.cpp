#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#define maxn 40005
#define M 1000000007
#define LL long long int
using namespace std;
int p[maxn];
bool vis[maxn];
int cnt;
int phi[maxn];
void init(){
    phi[1] = 1;
    for (int i = 2; i < maxn; i++){
        if (!vis[i]){
            p[cnt++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; j < cnt; j++){
            if (i * p[j] >= maxn) break;
            vis[i * p[j]] = 1;
            phi[i * p[j]] = phi[i] * (p[j] - 1);
            if (i % p[j] == 0) {
                phi[i * p[j]] = phi[i] * p[j];
                break;
            }
        }
    }
}
map<int, int> save;
int cal_phi(int x){
    if (x < maxn) return phi[x];
    if (save.count(x)) return save[x];
    int t = x;
    int con = (int) sqrt(x);
    int ans = 1;
    for (int i = 2; i <= con; i++){
        if (!vis[i] && x % i == 0){
            ans *= i - 1;
            x /= i;
            while (x % i == 0){
                ans *= i;
                x /= i;
            }
        }
    }
    if (x != 1) ans *= x - 1;
    return save[t] = ans;
}
void work(int n){
    LL ans = 0;
    int con = (int) sqrt(n);
    for (int i = 1; i < con; i++){
        if (n % i == 0){
            ans = (ans + (LL) n * i % M * cal_phi(i) % M) % M;
            ans = (ans + (LL) n * (n / i) % M * cal_phi(n / i) % M) % M;
        }
    }
    if (con * con == n){
        ans = (ans + (LL) n * con % M * cal_phi(con) % M) % M;
    }
    else if (n % con == 0){
        ans = (ans + (LL) n * con % M * cal_phi(con) % M) % M;
        ans = (ans + (LL) n * (n / con) % M * cal_phi(n / con) % M) % M;
    }
    ans = (M + ans - n) % M;
    ans = ans * ((M + 1) >> 1) % M;
    ans = (ans + n) % M;
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