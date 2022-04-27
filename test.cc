
#include <iostream>

template <typename T>
T getMaxNumber(T arr[], int size)
{
    T ret{arr[0]};
    for (int i = 0; i < size; ++i)
        ret = ret >= arr[i] ? ret : arr[i];
    return ret;
}
int factorial(int n, int sum)
{
    if (n == 1)
        return sum;
    return factorial(n - 1, sum * n);
}

int majorityElement(int nums[], int size)
{
    int freq{1};
    int ret{nums[0]};
    for (int i = 1; i < size; ++i)
    {
        if (nums[i] == ret)
            freq++;
        else
            freq--;
        if (!freq)
        {
            freq = 1;
            ret = nums[i];
        }
    }
    return ret;
}
int main()
{
    int nums[] = {1, 2, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 3, 3, 4, 5, 6, 7, 7, 7, 7, 7, 8, 9, 1, 2, 54, 3, 12};
    int size = sizeof(nums) / sizeof(nums[0]);
    std::cout << majorityElement(nums, size);
}
