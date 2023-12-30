#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &nums, int n, int root)
{
  int left = i * 2 + 1;
  int right = i * 2 + 2;

  int largest = root;

  if (left < n and nums[left] < nums[largest])
  {
    largest = left;
  }

  if (right < n and nums[right] < nums[largest])
  {
    largest = right;
  }

  if (root != largest)
  {
    swap(nums[root], nums[largest]);
    heapify(nums, n, largest);
  }
}

int heapSort(vector<int> &nums)
{
  for (int i = n / 2 - 1; i >= 0; i--)
  {
    // heapifying the ith element
    heapify(nums, n, i);
  }

  for (int i = n - 1; i > 0; i--)
  {
    swap(nums[i], nums[0]);
    heapify(nums, i, 0);
  }
}

int main()
{
  vector<int> nums = {3, 2, 1, 5, 1, 8, 2};
  int n = nums.size();

  heapSort(nums);

  for (auto &i : nums)
    cout << i << " ";

  return 0;
}