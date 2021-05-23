#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);

	int id=0,d=1,last=0,draw=0,id_last;
	vector<int> num(n);
	rep(i,m){
		string s; cin>>s;

		id_last=id;

		if(last!=0){
			if(s=="drawtwo" && last==2){
				num[id]++;
				id=(id+d+n)%n;
				draw+=2;
				continue;
			}
			else if(s=="drawfour" && last==4){
				num[id]++;
				id=(id+d+n)%n;
				draw+=4;
				continue;
			}
			else{
				num[id]-=draw;
				id=(id+d+n)%n;
				draw=0;
			}
		}

		id_last=id;

		num[id]++;
		if(s=="number"){
			id=(id+d+n)%n;
			last=0;
		}
		else if(s=="drawtwo"){
			id=(id+d+n)%n;
			last=draw=2;
		}
		else if(s=="drawfour"){
			id=(id+d+n)%n;
			last=draw=4;
		}
		else if(s=="skip"){
			id=(id+2*d+n)%n;
			last=0;
		}
		else{ // reverse
			d*=-1;
			id=(id+d+n)%n;
			last=0;
		}
	}

	printf("%d %d\n",id_last+1,num[id_last]);

	return 0;
}
