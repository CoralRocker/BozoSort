#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef enum {false, true} bool;

bool isInOrder(int* nums, size_t size);
void strArr(int* nums, size_t nsize, char* buf, size_t bsize);

void fill(int* nums, int min, int max, size_t size)
{
	for(int i = 0; i < size; i++)
	{
		nums[i] = rand() % (max - min) + min;
	}	
}

long long sort(int* nums, size_t size)
{
	long long c = 0;
	while(!isInOrder(nums, size))
	{
		int t1 = rand() % size,
		    t2 = rand() % size,
		    t3 = nums[t1];
		nums[t1] = nums[t2];
		nums[t2] = t3;
		c++;
		//char* buf = (char*)malloc(size*5);
		//strArr(nums, size, buf, size*5);
		//printf("Pass %ld: %s\n", c, buf);
		//free(buf);
	}
	return c;
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
void strArr(int* nums, size_t nsize, char* buf, size_t bsize) 
{
	for(int i = 0; i < nsize; i++)
	{
		sprintf(buf + i*4, "%03d ", nums[i]);
	}
}

int main(int argc, char** argv)
{
	srand(time(NULL));
	int* numbers = (argc >= 2) ? (int*)malloc(sizeof(int) * (argv[1][0] - 48)): (int*)malloc(sizeof(int) * 7);
	size_t nsize = (argc >= 2) ? argv[1][0] - 48 : 7;
	fill(numbers, 0, 100, nsize);
	char* buf = (char*)malloc(sizeof(char) * 4 * nsize);
	strArr(numbers, nsize, buf, 3 * nsize);
	printf("%s\n", buf);
	long long numPass = 0;
	int numTries = (argc >= 3) ? atoi(argv[2]) : 10;
	for(int i = 0; i < numTries; i++)
	{
		long long temp = sort(numbers, nsize);
		numPass += temp;
		fill(numbers, 0, 100, nsize);
	}
	sort(numbers, nsize);
	strArr(numbers, nsize, buf, 4 * nsize);
	printf("%s\nAVG Passes: %ld\n", buf, numPass/numTries);
	free(buf);
	
}
