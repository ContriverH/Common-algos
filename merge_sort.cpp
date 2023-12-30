#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums, int left, int mid, int right)
{
  int n1 = mid - left + 1;
  int n2 = right - mid;

  vector<int> leftNums(n1), rightNums(n2);

  for (int i = left, j = 0; i <= mid; i++, j++)
  {
    leftNums[j] = nums[i];
  }

  for (int i = mid + 1, j = 0; i <= right; i++, j++)
  {
    rightNums[j] = nums[i];
  }

  int i = 0;
  int j = 0;
  while (i < n1 and j < n2)
  {
    if (leftNums[i] < rightNums[j])
    {
      nums[left++] = leftNums[i++];
    }
    else
    {
      nums[left++] = rightNums[j++];
    }
  }

  while (i < n1)
  {
    nums[left++] = leftNums[i++];
  }

  while (j < n2)
  {
    nums[left++] = rightNums[j++];
  }
}

void mergeSort(vector<int> &nums, int left, int right)
{
  if (left >= right)
    return;

  int mid = left + (right - left) / 2;

  mergeSort(nums, left, mid);
  mergeSort(nums, mid + 1, right);
  merge(nums, left, mid, right);
}

void calc(vector<int> nums)
{
  int n = nums.size();
  mergeSort(nums, 0, n - 1);

  for (auto &i : nums)
    cout << i << " ";
  cout << endl;
}

int main()
{
  vector<int> nums = {44, 6, 46, 36, 20, 21, 28, 29, 30, 11};
  calc(nums);
  return 0;
}