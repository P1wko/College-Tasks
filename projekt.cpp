#include <iostream>
using namespace std;

int t0(int l, int cond)
{
	int T[l], min;
	for(int i = 0; i < l; i++)
	{
		cin >> T[i];
	}
	min = T[0];
	if(cond == 0)
	{
		for(int i = 1; i < l - 1; i++)
		{
			if(T[i] < min) min = T[i];
		}
		return min;
	}
	
	if(cond == 1)
	{
		for(int i = 0; i < l; i++)
		{
			for(int j = i + 1; j < l - 2; j++)
			{
				if(T[i] > T[j])
				{
					int temp = T[i];
					T[i] = T[j];
					T[j] = temp;
				}
			}
		}
		for (int i = 0; i < l; i++)
		{
			return T[i];
		}
	}
	
}

int main()
{
	int subprogram, ilosc;
	while(cin>>subprogram>>ilosc)
	{
		switch(subprogram)
		{
			case 0:
				{
					cout<<t0(ilosc, subprogram);
					break;
				}
			case 1:
				{
					cout<<subprogram<<" "<<t0(ilosc, subprogram)<<" ";
				}
			default: break;	
		}
		
	}
	return 0;
}
