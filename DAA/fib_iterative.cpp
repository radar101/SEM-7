#include<bits/stdc++.h>
using namespace std;


int fibIterative(int n)
{
	int a = 0, b = 1, fib;
	for(int i=2;i<=n;i++)
	{
		fib = a + b;
		a = b;
		b = fib;
	}
	return b;
}

int main()
{
	int n = 6;
	int ans = fibIterative(n);
	cout<<ans<<endl;
}