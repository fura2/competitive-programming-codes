#include <algorithm>
#include <iostream>

using namespace std;

int main(){
	int n,a,b; cin>>n>>a>>b;
	cout<<max(a+b-n,0);
	return 0;
}
