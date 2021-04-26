#include <pthread.h>
#include <stdio.h>
//#include <time.h>
#include <stdlib.h>

int *arr1;
int *arr2;

typedef struct
{
	int index;
	int size;
}parameters;

void *Sort(void* s)
{
	parameters* s1 = (parameters*)s;
	int index = s1->index;
	int size = s1->size;

	for(int i = 1+index; i < size+index; i++)
	{
		int key = arr1[i];
		int j = i-1;
		while(key < arr1[j] && j>=0)
		{
			arr1[j+1] = arr1[j];
			j--;
		}
		arr1[j+1] = key;
	}

	pthread_exit(NULL);
}

void *Merge(void* s)
{
	parameters* s1 = (parameters*)s;
	
	
	int num = s1->size;
	int i = 0, j = s1->index, k = 0;
	while( i < num/2 && j < num)
	{
		if(arr1[i]<=arr1[j])
		{
			arr2[k] = arr1[i];
			k++;
			i++;
		}
		else
		{
			arr2[k] = arr1[j];
			k++;
			j++;
		}
	}
	
	if(i != num/2)
	{
		for(int u = i; u < num/2; u++)
		{
			arr2[k] = arr1[i];
			k++;
			i++;
		}
	}
	else
	{
		for(int u = j; u < num; u++)
		{
			arr2[k] = arr1[j];
			k++;
			j++;
		}
	}
	pthread_exit(NULL);
}

int main()
{
	int num = 0;
	scanf("%d", &num);

	//set up array
	arr1 = (int*)malloc(sizeof(int)*num);
	arr2 = (int*)malloc(sizeof(int)*num);
	for(int i = 0; i < num; i++)
	{
		scanf("%d", &arr1[i]);
	}
	for(int i = 0; i < num; i++)
	{
		arr2[i] = 0;
	}

	//set up parameters
	parameters* p1 = (parameters*)malloc(sizeof(parameters)*1);
	p1->index = 0;
	p1->size = num/2;

	parameters* p2 = (parameters*)malloc(sizeof(parameters)*1);
	p2->index = num/2;
	p2->size = num-num/2;

	parameters* p3 = (parameters*)malloc(sizeof(parameters)*1);
	p3->index = num/2;
	p3->size = num;
	
	
	//create child threads12
	pthread_t tid1;
	pthread_attr_t attr1;

	pthread_attr_init(&attr1);
	pthread_create(&tid1, &attr1, Sort, p1);
	pthread_join(tid1, NULL);
	
	pthread_t tid2;
	pthread_attr_t attr2;

	pthread_attr_init(&attr2);
	pthread_create(&tid2, &attr2, Sort, p2);
	pthread_join(tid2, NULL);
	
	for(int i = 0; i < num; i++)
	{
		printf(" %d", arr1[i]);
	}
	printf("\n");
	
	//create child threads3
	pthread_t tid3;
	pthread_attr_t attr3;
	
	pthread_attr_init(&attr3);
	pthread_create(&tid3, &attr3, Merge, p3);
	pthread_join(tid3, NULL);
	
	for(int i = 0; i < num; i++)
	{
		printf(" %d", arr2[i]);
	}

	return 0;
}

















