#ifndef _STATICLINKLIST_H_
#define _STATICLINKLIST_H_

#define  MAXSIZE 20
typedef int elemtype;

typedef struct _STATICLINKLIST
{
	elemtype data;
	int cur;
}LINKLIST;

typedef LINKLIST STATICLINKLIST[MAXSIZE];

bool initlinklist(STATICLINKLIST space);

bool insert(STATICLINKLIST space,int pos,elemtype e);
bool del(STATICLINKLIST space,int pos);

int getlength(STATICLINKLIST space);
bool show(STATICLINKLIST space);

int malloc_sll(STATICLINKLIST space);
void free_sll(STATICLINKLIST space,int pos);

#endif