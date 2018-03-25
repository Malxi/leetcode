#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

void add(int *arr, int **res, int *returnSize){
	int l;
	int dup = 0;
    /* O(n) */
	for(l = 0; l < *returnSize; l++){
		if(res[l][0] == arr[0] && res[l][1] == arr[1] &&
		res[l][2] == arr[2] && res[l][3] == arr[3]){
			dup = 1;
			break;
		}
	}

	if(!dup){
		res[*returnSize] = arr;
		(*returnSize)++;
		//printf("%d %d %d %d\n", arr[0], arr[1], arr[2], arr[3]);
	}else{
		free(arr);
	}
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
	int **res;
	int i, j, k, l;
	int a, b, c, d, cd;
	int dup;
	int *arr;
	int st, ed;
	int max, min;
	int low, high;
	
	*returnSize = 0;
    res = (int **)malloc(sizeof(int *)*1000);
	qsort(nums, numsSize, sizeof(int), comp);
	
	if(numsSize < 4){
		*returnSize = 0;
		return res;
	}
	
    /* Optimize */
	st = numsSize - 1;
	ed = 0;
	for(i = 0; i < numsSize - 3; i++){
		min = nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3];
		max = nums[i] + nums[numsSize - 1] + nums[numsSize - 2] + nums[numsSize - 3];
		if(target >= min && target <= max){
			if(st > i) st = i;
			if(ed < i) ed = i;
		}
	}

	if(st > ed){
		*returnSize = 0;
		return res;
	}
    
    /* O(n^3) */
	for(i = st; i < ed + 1; i++){
		a = nums[i];
		for(j = i + 1; j < numsSize - 2; j++){
			b = nums[j];
			cd = target - a - b;
			low = j + 1;
			high = numsSize - 1;
			while(low < high){
				c = nums[low];
				d = nums[high];
				if(c + d == cd){
					arr = (int *)malloc(sizeof(int) * 4);
					arr[0] = a;
					arr[1] = b;
					arr[2] = c;
					arr[3] = d;
					add(arr, res, returnSize);
					low += 1;
					high -= 1;
				}else if(c + d < cd){
					low += 1;
				}else
					high -= 1;
			}
		}
	}
	return res;
}

int main(){
	int nums[] = {1, 0, -1, 0, -2, 2};
	int returnSize = 0;
	int numsSize = 6;
	int target = 0;
	
	fourSum(nums, numsSize, target, &returnSize);
	return 0;
}
