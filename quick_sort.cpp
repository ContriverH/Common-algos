#include <bits/stdc++.h>
using namespace std;

// Advantage: the main advantage of this algo over quick sort is that it does in-place sorting
// The auxillary space used by Quick sort is O(1) only
// while in case of merge sort it is O(n)

int partition(vector<int> &nums, int left, int right)
{
  int pivot = nums[right];
  int pi = left;

  for (int i = left; i <= right; i++)
  {
    if (nums[i] <= pivot)
    {
      swap(nums[i], nums[pi]);
      pi += 1;
    }
  }
  swap(nums[pi], nums[right]);
  return pi;
}

void quickSort(vector<int> &nums, int left, int right)
{
  if (left >= right)
    return;

  int n = nums.size();

  int pivotIndex = partition(nums, left, right);
  quickSort(nums, left, pivotIndex - 1);
  quickSort(nums, pivotIndex + 1, right);
}

int main()
{
  vector<int> nums = {3, 2, 1, 5, 1, 8, 2};
  int n = nums.size();

  quickSort(nums, 0, n - 1);
  for (auto &i : nums)
    cout << i << " ";
  return 0;
}