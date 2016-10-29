#include "STATICLINKLIST.h"
#include <stdio.h>

bool initlinklist(STATICLINKLIST space)
{
	for (int i=0;i<MAXSIZE-1;i++)
	{
		space[i].cur = i+1;
	}
	space[MAXSIZE-1].cur = 0;
	return true;
}

int getlength(STATICLINKLIST space)
{
	int i = space[MAXSIZE-1].cur;
	int len = 1;
	while (i)
	{
		i = space[i].cur;
		len++;
	}
	return len;
}

int malloc_sll(STATICLINKLIST space)
{
	int i = space[0].cur;
	if (space[0].cur)
	{
		space[0].cur = space[i].cur;
	}
	return i;
}
bool insert(STATICLINKLIST space,int pos,elemtype e)
{
	if (pos<1||pos>getlength(space))
	{
		return false;
	}
	int j = malloc_sll(space);
	int k = MAXSIZE-1;
	for (int i=1;i<=pos-1;i++)
	{
		k = space[k].cur;
	}
	space[j].data = e;
	space[j].cur = space[k].cur;
	space[k].cur = j;	
	return true;
}


void free_sll(STATICLINKLIST space,int pos)
{
	space[pos].cur = space[0].cur;
	space[0].cur = pos;
}
bool del(STATICLINKLIST space,int pos)
{
	if (pos<1 ||pos>getlength(space)-1)
	{
		return false;
	}
	int k = MAXSIZE-1;
	for (int i=1;i<pos;i++)
	{
		k = space[k].cur;
	}
	int j = space[k].cur;
	space[k].cur = space[j].cur;
	free_sll(space,j);
	return true;
}

bool show(STATICLINKLIST space)
{
	int k = MAXSIZE-1;
	int j = getlength(space);
	for (int i=1;i<j;i++)
	{
		k = space[k].cur;
		printf("%d ",space[k].data);                
	}
	printf("\n");
	return true;
}