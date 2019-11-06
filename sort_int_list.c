#include <stdio.h>
#include <stdlib.h>

*/This is a  C program that sort an integer list in an ascending order, regardless of how messy thev data was*/

int  check(int *tab, unsigned int sze)
{
	int i = 0;
	while (i < sze){
		if (tab[i] >= tab[i + 1])
			i++;
		else
			return 0;
	}
	return 1;
}

void  swap(int *tab, int a)
{
	int b = a + 1;
	int tmp;
	tmp = tab[a];
	tab[a] = tab[b];
	tab[b] = tmp;
}

void    sort_int(int *tab, unsigned int size)
{
	int i, j, k;
	int tmp;
	int *sm;

	sm = tab;
	i = 0;
	j = 10;
	k = 1;
	while (i < size)
	{
		if (sm[i] < sm[k] && k <= size)
			swap(tab, i);
		else
		{
			i++;
			k++;
		}
	}
	j = check(tab, size);
	if (j == 0)
	{
		sort_int(tab,size);
	}
}

int    main(void)
{
	int n;
	int *intarr;

	printf("How many numbers are in your sort list?\nPlease enter your number here:");
	scanf("%d", &n);
	printf("\nEnter your list, *note: one item at a time, then press enter");
	intarr = (int *)malloc(n*sizeof(int));
	for (int x = 0; x < n; x++){
		scanf("%d", &intarr[x]);
		printf(" %d ", intarr[x]);}
	printf("\nYou have entered: ");
	for (int s = 0; s <n; s++)
		printf("%d ", intarr[s]); 
	sort_int(intarr, n);
	printf("\nYour sorted list is:");
	for(int z = 0; z < n; z++)
		printf(" %d ", intarr[z]);
	printf("\ndone!");
	free(intarr);
	return 0;
}
