#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

vector<int> rotx(vector<int> D){
	tie(D[0],D[1],D[5],D[4])=make_tuple(D[1],D[5],D[4],D[0]);
	return D;
}

vector<int> roty(vector<int> D){
	tie(D[0],D[2],D[5],D[3])=make_tuple(D[2],D[5],D[3],D[0]);
	return D;
}

vector<int> rotz(vector<int> D){
	tie(D[1],D[3],D[4],D[2])=make_tuple(D[3],D[4],D[2],D[1]);
	return D;
}

int main(){
	int n; cin>>n;

	int ans=1;
	vector<int> D={1,2,3,4,5,6};
	rep(_,n){
		string s; cin>>s;
		if(s=="North"){
			D=rotx(D);
		}
		else if(s=="East"){
			D=roty(D);
			D=roty(D);
			D=roty(D);
		}
		else if(s=="South"){
			D=rotx(D);
			D=rotx(D);
			D=rotx(D);
		}
		else if(s=="West"){
			D=roty(D);
		}
		else if(s=="Right"){
			D=rotz(D);
			D=rotz(D);
			D=rotz(D);
		}
		else{ // Left
			D=rotz(D);
		}
		ans+=D[0];
	}
	cout<<ans<<'\n';

	return 0;
}
