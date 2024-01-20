#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

struct S
{
	int n;
	int arr[0];
};


int main()
{
	struct S* p = (struct S*)malloc(sizeof(struct S) + 10 * sizeof(int));
	int i = 0;
	if (p != NULL)
	{
		p->n = 10;
		printf("n的值为%d\n", p->n);
		for (i = 0; i < 10; i++)
		{
			p->arr[i] = i;
		}
		for (i = 0; i < 10; i++)
		{
			printf("柔性数组成员arr[%d]的值为%d\n", i, p->arr[i]);
		}
	}
/*	free(p);
	p = NULL*/;
	//重新设定柔性数组的成员数量;
	struct S* ps = realloc(p, 204);
	if (ps != NULL)
	{
		for (i = 10; i < 50; i++)
		{
			ps->arr[i] = i;
		}
		for (i = 0; i < 50; i++)
		{
			printf("柔性数组成员arr[%d]的值为%d\n", i, ps->arr[i]);
		}
	}
	/*free(ps);
	ps = NULL;
	free(p);
	p = NULL;*/
	free(ps);
	ps = NULL;
	return 0;
}