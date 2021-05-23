#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string f[128];
	f['a']="う　し　";
	f['b']="う　あ　";
	f['c']="ん　笑　";
	f['d']="た　ぷ　";
	f['e']="く　ん　";
	f['f']="ぷ　に　";
	f['g']="し　き　";
	f['h']="あ　く　";
	f['i']="う　く　";
	f['j']="あ　笑　";
	f['k']="う　ん　";
	f['l']="し　ぷ　";
	f['m']="う　き　";
	f['n']="く　笑　";
	f['o']="う　笑　";
	f['p']="に　き　";
	f['q']="ぷ　笑　";
	f['r']="た　き　";
	f['s']="た　ん　";
	f['t']="し　あ　";
	f['u']="し　ん　";
	f['v']="う　う　";
	f['w']="う　た　";
	f['x']="き　笑　";
	f['y']="に　く　";
	f['z']="笑　笑　";

	string s; cin>>s;
	for(char c:s) cout<<f[c];
	cout<<'\n';
	
	return 0;
}
