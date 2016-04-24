// uloha-7-1.c -- Tyzden 7 - Uloha 1
// Ronald Demeter, 5.11.2015 14:52:05
#include <stdio.h>
 
typedef unsigned long long ull;
 
ull binomial(ull m, ull n)
{
	ull r = 1, d = m - n;
	if (d > n) { n = d; d = m - n; }
 
	while (m > n) {
		r *= m--;
		while (d > 1 && ! (r%d) ) r /= d--;
	}
 
	return r;
}
 
ull catalan1(int n) {
	return binomial(2 * n, n) / (1 + n);
}
 
ull catalan2(int n) {
	int i;
	ull r = !n;
 
	for (i = 0; i < n; i++)
		r += catalan2(i) * catalan2(n - 1 - i);
	return r;
}
 
ull catalan3(int n)
{
	return n ? 2 * (2 * n - 1) * catalan3(n - 1) / (1 + n) : 1;
}
int main()
{
	int i;
	while ((scanf("%d", &i))>0){
		
		printf("%llu\n", catalan3(i));
	}

	return 0;
}