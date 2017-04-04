#include <iostream>
#include <vector>
using namespace std;

//Given an unsorted integer array, find the first missing positive integer.
//For example,
//Given[1, 2, 0] return 3,
//and[3, 4, -1, 1] return 2.
//Your algorithm should run in O(n) time and uses constant space.

int firstMissingPositive(vector<int>& nums) {
	int size = (int)nums.size();
	if (size == 0) {
		return 1;
	}
	for (int i = 0; i < size; i++) {
		if (nums[i] == 0) {
			nums[i] --;
		}
	}//has no 0
	int i = 0;

	int num = nums[i];
	while (i < size) {
		if (num <= 0 || num>size) {
			i++;
			if (i < size) {
				num = nums[i];
			}

		}
		else {
			int tmp = nums[num%size];
			nums[num%size] = 0;
			num = tmp;
		}
	}
	int res = 1;
	while (res<size && nums[res] == 0) {
		res++;
	}
	if (res == size&&nums[0] == 0) {
		res++;
	}

	return res;
}

int main() {
	vector<int> nums = { 3,4,-1,1 };
	cout << firstMissingPositive(nums) << endl;
	return 0;
}