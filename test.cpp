#include <iostream>
using namespace std;

int funkcja(int ilosc, int loop)
{
	int T[1000], temp;
	for(int i = 0; i < ilosc; i++)
	{
		cin>>T[i];
	}
	
	for(int i = 0; i < ilosc; i++)
	{
		for(int j = i + 1; j < ilosc; j++)
		{
			if(T[i] > T[j])
			{
				temp = T[i];
				T[i] = T[j];
				T[j] = temp;
			}
		}
	}
	
	
}

int main()
{
	int l;
	cin>>l;
	for(int i = 0; i < ilosc; i++)
	{
		cout<<funkcja(l, i)<<" ";
	}
	
}
