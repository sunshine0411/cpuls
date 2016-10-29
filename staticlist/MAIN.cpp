#include "STATICLINKLIST.h"


int main()
{
	STATICLINKLIST space;
	initlinklist(space);
	for (int i=1;i<5;i++)
	{
		insert(space,i,10*i);
	}
	insert(space,3,-300);
	insert(space,1,-100);
	insert(space,7,70);

	del(space,1);
	del(space,3);
	del(space,5);
	show(space);
	return 0;
}