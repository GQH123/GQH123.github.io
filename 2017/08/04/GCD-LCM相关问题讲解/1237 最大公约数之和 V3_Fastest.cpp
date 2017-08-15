#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<ctime>
#include<cstdlib>
#include<string>
#include<queue>
#include<cmath>
#include<set>
#include<map>
#include<bitset>
#include<vector>
#define Rep(x,a,b) for (int x=a;x<=(int)b;x++)
#define Drp(x,a,b) for (int x=a;x>=(int)b;x--)
#define Cross(x,a) for (int x=Hd[a];~x;x=Nx[x])
#define ll long long
#define INF (1<<29)
#define PII pair<int,int>
#define PDD pair<double,double>
#define mk(a,b) make_pair(a,b)
#define fr first
#define sc second
using namespace std;
inline ll Rd(){
	ll x=0;int ch=getchar(),f=1;
	while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();
	if (ch=='-'){f=-1;ch=getchar();}
	while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return x*f;
}
inline void Rt(ll x){
	if (x<0) putchar('-'),x=-x;
	if (x>=10) Rt(x/10),putchar(x%10+'0');
		else putchar(x+'0');
}
const int N=5000000;
int Mn[N+5],Phi[N+5],Prm[400000],Cnt;
int Ans[2160],Vs[2160];
#define P 1000000007
int Sum(ll x){
	return (x%P)*((x+1)%P)%P*500000004%P;
}
int Calc(ll Ori,ll Div){
	ll n=Ori/Div;
	if (n<=N) return Phi[n];
	if (Vs[Div]) return Ans[Div];
	Vs[Div]=1;Ans[Div]=Sum(n);
	for (int i=1;(ll)i*i<=n;i++){
		if (i>1&&i!=n/i) Ans[Div]-=Calc(Ori,Div*i),Ans[Div]+=Ans[Div]<0?P:0;
		Ans[Div]-=(n/i-n/(i+1))*Phi[i]%P,Ans[Div]+=Ans[Div]<0?P:0;
	}
	return Ans[Div];
}
int main(){
	Phi[1]=1;
	Rep(i,2,N){
	 	if (!Mn[i]) Prm[Mn[i]=++Cnt]=i,Phi[i]=i-1;
		Rep(j,1,Cnt){
			int k=Prm[j]*i;
			if (k>N) break;
			Mn[k]=j;
			if (j==Mn[i]){Phi[k]=Phi[i]*Prm[j];break;}
				else Phi[k]=Phi[i]*(Prm[j]-1);
		}
	}
	Rep(i,2,N) Phi[i]+=Phi[i-1],Phi[i]-=Phi[i]>=P?P:0;
	ll n=Rd();
	int Ans=0;
	for (int i=1;(ll)i*i<=n;i++){
		if (i!=n/i) Ans+=(ll)i*Calc(n,i)%P,Ans-=Ans>=P?P:0;
		Ans+=(ll)(Sum(n/i)+P-Sum(n/(i+1)))%P*Phi[i]%P,Ans-=Ans>=P?P:0;
	}
	Ans=Ans*2%P+P-Sum(n),Ans-=Ans>=P?P:0;
	Rt(Ans);
}