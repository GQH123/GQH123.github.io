#include <cstdlib>
#include <cstdio>
#include <algorithm>
#define LL long long int
using namespace std;
LL gcd(LL a, LL b){
    return (!b) ? a : gcd(b, a % b);
}
int main(){
    freopen("lcm.in", "r", stdin);
    freopen("lcm.out", "w", stdout);
    LL a, b;
    scanf("%lld%lld", &a, &b);
    printf("%lld", a * b / gcd(a, b));
    return 0;
}