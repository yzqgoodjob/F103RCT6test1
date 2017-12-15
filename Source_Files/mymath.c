#include "mymath.h"
#include "includes.h"

int limit(int x, int min, int max)
{
	if(x<min) return (min);
	else if(x>max) return (max);
	else return (x);
}

int limit_change(int x, int x_old, int zoom)
{
	int t;
	t = x;
	if(abs(x-x_old)>zoom)
	{
		if(x>x_old)
		{
			t = x_old + zoom;
		}
		else
		{
			t = x_old - zoom;
		}
	}
	
	return (t);
}
