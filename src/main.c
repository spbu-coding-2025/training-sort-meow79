#include <stdio.h>
#include <stdlib.h>
#define MAX_ARRAY_SIZE 100

int read_nums_and_write_in_arr(int *arr, int arr_len)
{
	int cnt_elements = 0;
	for (int i = 0; i < arr_len; ++i)
	{
		int rc = scanf("%d", arr + i);
		if (rc != 1)
		{
			return cnt_elements;
		}
		++cnt_elements;
	}
	return cnt_elements;
}

void print_nums_from_arr(int *arr, int arr_len)
{
	for (int i = 0; i < arr_len; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int* merge_sort(int *arr, int arr_len)
{
	if (arr_len == 1)
	{
		return arr;
	}
	else
	{
		int left_part_len = arr_len / 2;
		int right_part_len = (arr_len / 2) + (arr_len % 2);
		int *left_part = arr;
		int *right_part = arr + left_part_len;
		
		left_part = merge_sort(left_part, left_part_len);
		right_part = merge_sort(right_part, right_part_len);

		int *temp_arr = malloc(arr_len * sizeof(arr[0]));
		int i = 0, j = 0, k = 0;
		while (i < left_part_len && j < right_part_len)
		{
			if (left_part[i] > right_part[j])
			{
				temp_arr[k] = right_part[j];
				++j;
			}
			else
			{
				temp_arr[k] = left_part[i];
				++i;
			}
			++k;
		}
		while (i < left_part_len)
		{
			temp_arr[k] = left_part[i];
			++i;
			++k;
		}
		while (j < right_part_len)
		{
			temp_arr[k] = right_part[j];
			++j;
			++k;
		}

		for (int i = 0; i < arr_len; ++i)
		{
			arr[i] = temp_arr[i];
		}
		free(temp_arr);

		return arr;
	}
}

int main()
{
	int arr[MAX_ARRAY_SIZE] = {};
	int arr_len = sizeof(arr) / sizeof(arr[0]);
	arr_len = read_nums_and_write_in_arr(arr, arr_len);

	int *sorted_arr = merge_sort(arr, arr_len);

	print_nums_from_arr(sorted_arr, arr_len);
	return 0;
}
