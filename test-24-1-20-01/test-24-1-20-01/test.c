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
		printf("n��ֵΪ%d\n", p->n);
		for (i = 0; i < 10; i++)
		{
			p->arr[i] = i;
		}
		for (i = 0; i < 10; i++)
		{
			printf("���������Աarr[%d]��ֵΪ%d\n", i, p->arr[i]);
		}
	}
/*	free(p);
	p = NULL*/;
	//�����趨��������ĳ�Ա����;
	struct S* ps = realloc(p, 204);
	if (ps != NULL)
	{
		for (i = 10; i < 50; i++)
		{
			ps->arr[i] = i;
		}
		for (i = 0; i < 50; i++)
		{
			printf("���������Աarr[%d]��ֵΪ%d\n", i, ps->arr[i]);
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