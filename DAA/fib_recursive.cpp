#include<bits/stdc++.h>
using namespace std;

int fibRecursive(int n) {
	if(n <= 1) return n;
	return fibRecursive(n-1) + fibRecursive(n-2);
}

int main()
{
	int n = 2;
	int ans = fibRecursive(n);
	cout<<ans<<endl;
}