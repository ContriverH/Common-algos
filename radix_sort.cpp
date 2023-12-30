// Advantage: sorting an array of words or strings lexicographically.

#include <bits/stdc++.h>
using namespace std;

int calcNumberOfDigits(int num)
{
  int cnt = 0;
  while (num)
  {
    cnt += 1;
    num /= 10;
  }

  return cnt;
}

vector<int> calc(vector<int> nums)
{
  int n = nums.size();
  int pos = 1;
  int mxNum = 0;
  int mxNumberOfDigits = 0; // no. of digits of maximum number

  mxNum = *max_element(nums.begin(), nums.end());
  mxNumberOfDigits = calcNumberOfDigits(mxNum);

  for (int i = 1; i <= mxNumberOfDigits; i++)
  {
    vector<vector<int>> adj(10);
    for (auto num : nums)
    {
      adj[(num / pos) % 10].push_back(num);
    }

    nums = {};
    for (auto &place : adj)
    {
      for (int num : place)
      {
        nums.push_back(num);
      }
    }

    pos *= 10;
  }

  return nums;
}

int main()
{
  vector<int> nums = {21, 11, 41, 32, 61, 31};
  vector<int> result = calc(nums);

  // Print the sorted result
  for (int num : result)
  {
    cout << num << " ";
  }

  return 0;
}