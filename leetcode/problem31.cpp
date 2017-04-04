#include <vector>
#include <iostream>
using namespace std;

//Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
//If such arrangement is not possible, it must rearrange it as the lowest possible order(ie, sorted in ascending order).
//The replacement must be in - place, do not allocate extra memory.
//Here are some examples.Inputs are in the left - hand column and its corresponding outputs are in the right - hand column.
//1, 2, 3 ¡ú 1, 3, 2
//3, 2, 1 ¡ú 1, 2, 3
//1, 1, 5 ¡ú 1, 5, 1

void nextPermutation(vector<int>& nums) {
	if (nums.size() <= 1) {
		return;
	}
	if (nums.size() == 2) {
		swap(nums[0], nums[1]);
		return;
	}
	int i = nums.size() - 2;
	for (; i >= 0; i--) {
		if (nums[i] < nums[i + 1]) {
			for (int j = nums.size() - 1; j > i; j--) {
				if (nums[j] > nums[i]) {
					swap(nums[i], nums[j]);
					break;
				}
			}
			i++;
			for (int k = nums.size() - 1; k > i; k--, i++) {
				swap(nums[k], nums[i]);
			}
			return;

		}
	}
	i = 0;
	for (int k = nums.size() - 1; k > i; k--, i++) {
		swap(nums[k], nums[i]);
	}
	return;
}
int problem31() {
	vector<int> nums = { 1,1,5 };
	for (int i = 0; i < (int)nums.size(); i++) {
		cout << nums[i] << "\t";
	}
	cout << endl;
	nextPermutation(nums);
	for (int i = 0; i < (int)nums.size(); i++) {
		cout << nums[i] << "\t";
	}
	cout << endl;
	return 0;
}
