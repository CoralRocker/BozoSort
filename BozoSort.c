#include <stdio.h>
#include <stdlib.h>
typedef enum {false, true} bool;

void fill(int* nums, int min, int max, size_t size)
{
	for(int i = 0; i < size; i++)
	{
		srand(time(NULL));
		nums[i] = rand() % (max - min) + min;
	}	
}

long long sort(int* nums, size_t size)
{
	long long c = 0;
	while(!isInOrder(nums, size)
	{
		int t1 = rand() % size,
		    t2 = rand() % size;
		    t3 = nums[t1];
		nums[t1] = nums[t2];
		nums[t2] = t3;
		c++;
	}
}

bool isInOrder(int* nums, size_t size)
{
	if(size <= 1)
		return true;
	for(int i = 1; i < size; i++)
	{
		if(nums[i] < nums[i-1])
			return false;
	}
	return true;
}
void strArr(int* nums, size_t nsize, char* buf, size_t bsize); 
{
	
}

int main(int argc, char** argv)
{
	
	int* numbers = (argc >= 2) ? (int*)malloc(sizeof(int) * (argv[1][0] - 48)): (int*)malloc(sizeof(int) * 7);
	size_t nsize = (argc >= 2) ? argv[1][0] - 48 : 7;
	fill(numbers, 0, 100, nsize);
	char* buf = (char*)malloc(sizeof(char) * 3 * size);
	strArr(numbers, nsize, buf, 3 * size);
	printf("%s\n", buf);
	long long numPass = 0;
	for(int i = 0; i < (argc >= 3) ? atoi(argv[2]) : 10; i++)
	{
		long long temp = sort(numbers, nsize);
		numPass += temp;
		fill(numbers, 0, 100, nsize);
	}
	printf("Number passes: %ld\n", numPass);
}
