#include "mymath.h"
#include "includes.h"

int limit(int x, int min, int max)
{
	if(x<min) return (min);
	else if(x>max) return (max);
	else return (x);
}

int limit_delta(int x, int x_old, int zoom)
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

void fun_sort(u8 *list, u8 num)//排序从小到大
{
	u8 i,j;
	u8 temp;
	for(i=0; i<num-1; i++)
	{
		for(j=i+1; j<num; j++)
		{
			if(*(list+i)>*(list+j))
			{
				temp = *(list+i);
				*(list+i) = *(list+j);
				*(list+j) = temp;
			}
		}
	}
}
