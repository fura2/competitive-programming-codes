#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

double sigmoid(double x){
	return 1/(1+exp(-x));
}

template<class F>
double integral(F f){
	int N=1000;
	double res=0;
	rep(i,N){
		double x=-3.0*(N-i)/N+3.0*i/N;
		res+=f(x);
	}
	res*=6.0/N;
	return res;
}

void solve(){
	int n=100,m=10000;
	vector<string> s(n);
	rep(i,n) cin>>s[i];

	// estimate skills
	vector<double> skill(n,3);
	{
		int N=600;
		vector<double> I(N);
		rep(t,N){
			double a=-3.0*(N-t)/N+3.0*t/N;
			I[t]=integral([&](double x){
				return sigmoid(a-x);
			})/6;
		}
		rep(i,n){
			double ave=1.0*count(s[i].begin(),s[i].end(),'1')/m;
			rep(t,N) if(ave<I[t]) {
				double a=-3.0*(N-t)/N+3.0*t/N;
				skill[i]=a;
				break;
			}
		}
	}

	// estimate difficulties
	vector<double> diff(m,3);
	{
		int N=600;
		vector<double> S(N);
		rep(t,N){
			double a=-3.0*(N-t)/N+3.0*t/N;
			rep(i,n){
				S[t]+=sigmoid(skill[i]-a);
			}
			S[t]/=n;
		}
		rep(j,m){
			double ave=0;
			rep(i,n) if(s[i][j]=='1') ave++;
			ave/=n;
			rep(t,N) if(ave>S[t]) {
				double a=-3.0*(N-t)/N+3.0*t/N;
				diff[j]=a;
				break;
			}
		}
	}

	vector<int> p(n);
	iota(p.begin(),p.end(),0);
	sort(p.begin(),p.end(),[&](int i,int j){
		return skill[i]<skill[j];
	});
	vector<int> q(m);
	iota(q.begin(),q.end(),0);
	sort(q.begin(),q.end(),[&](int i,int j){
		return diff[i]<diff[j];
	});

	vector<int> cnt(n);
	rep(i,n){
		rep(j,m/20) if(s[p[i]][q[m-1-j]]=='1') cnt[i]++;
	}
	vector<int> gap(n);
	gap[0]=cnt[0]-cnt[1];
	for(int i=1;i<n-1;i++) gap[i]=(cnt[i]-cnt[i-1])+(cnt[i]-cnt[i+1]);
	gap[n-1]=cnt[n-1]-cnt[n-2];

	printf("%d\n",p[max_element(gap.begin(),gap.end())-gap.begin()]+1);
}

int main(){
	int t; scanf("%d%*d",&t);
	rep(_,t){
		printf("Case #%d: ",_+1);
		solve();
	}
	return 0;
}
