#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define maxn 100005
#define LL long long int
using namespace std;
int cnt;
int p[maxn];
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
int cal_phi(int x){
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
    return ans;
}
void work(int n){
    int con = (int)sqrt(n);
    LL ans = 0;
    for (int i = 1; i < con; i++){
        if (n % i == 0){
            ans += (LL)cal_phi(i) * n / i;
            ans += (LL)cal_phi(n / i) * i;
        }
    }
    if (con * con == n){
        ans += (LL)cal_phi(con) * con;
    }
    else if (n % con == 0){
        ans += (LL)cal_phi(con) * n / con;
        ans += (LL)cal_phi(n / con) * con;
    }
    printf("%lld", ans);
}
int main(){
    freopen("sum.in", "r", stdin);
    freopen("sum.out", "w", stdout);
    init();
    int n;
    scanf("%d", &n);
    work(n);
    return 0;
}