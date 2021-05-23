#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int parse(string str){
	int h,m,s,ms;
	sscanf(str.c_str(),"%d:%d:%d.%d",&h,&m,&s,&ms);
	return (((h-21)*60+m)*60+s)*1000+ms;
}

int main(){
	int n; cin>>n;
	vector<int> l(n),r(n);
	rep(i,n){
		string s,t; cin>>s>>t;
		l[i]=parse(s);
		r[i]=parse(t);
	}

	int L=-1,R=INF;
	rep(i,n) if(l[i]>=r[i]) {
		L=max(L,l[i]);
		R=min(R,r[i]+1000);
	}
	rep(i,n){
		if(l[i]>=r[i]){
			printf("%d\n",r[i]-l[i]+1000);
		}
		else{
			if(r[i]<=L-1000 || R<=l[i]){
				printf("%d\n",r[i]-l[i]);
			}
			else if(l[i]<=L-1000 && R<=r[i]){
				printf("%d\n",r[i]-l[i]+1000);
			}
			else{
				puts("-1");
			}
		}
	}

	return 0;
}
