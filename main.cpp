#include <iostream>

int v[100];
int main()
{
	int n, m = 0; 
	std::cin>>n;
	for( int i = 1; i <= 2 * n; ++i )
		std::cout<< i << " ";
	std::cout << "\n";
	for( int i = 1; i <= 2 * n; ++i )
	{
		if ( i % 2 == 0) v[i-1] = i; 
		else v[i-1] = 2*n-i;
		for(int j = 0; j < i-1; j++)
			if(v[j] > v[i-1]) m++;
		std::cout << v[i-1] << " ";
	}	
	std::cout<<"\nm = "<< m <<"\n";
	system("pause");
}
