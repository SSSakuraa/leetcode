#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
//Try to solve it in linear time / space.
//Return 0 if the array contains less than 2 elements.
//You may assume all elements in the array are non - negative integers and fit in the 32 - bit signed integer range.

//参考思路：
//若有8个数据，最大数和最小数的差值为15，则至少有一个gap>=3
//则把8个数据进行分类，每一类的最大gap小于3
//则最大的gap一定产生于不同的分类中
//由此，我们只需要记录每一类中的最小数据和最大数据即可

int ceil(int a, int b)//the ceil of (a/b) is (a+b-1)/b
{
	return (a + b - 1) / b;
}

int maximumGap(vector<int>& nums) {
	if (nums.size() < 2)
		return 0;

	auto min_max = minmax_element(nums.begin(), nums.end());
	int min_num = nums[min_max.first - nums.begin()];
	int max_num = nums[min_max.second - nums.begin()];
	if (min_num == max_num)
		return 0;
	int gap = ceil(max_num - min_num, nums.size() - 1);
	vector<pair<bool,pair<int,int>>> v(ceil(max_num - min_num+1,gap));//the border of each class
	for (int i = 0; i < v.size(); i++) {
		v[i].first = false;
	}
	for (int i = 0; i < nums.size(); i++) {
		pair<bool, pair<int, int>> &p = v[(nums[i] - min_num) / gap];
		if (p.first) {
			p.second.first = min(nums[i], p.second.first);
			p.second.second = max(nums[i], p.second.second);
		}
		else {
			p.first = true;
			p.second.first = nums[i];
			p.second.second = nums[i];
		}
		
	}
	int res=gap;
	int tmp=v[0].second.second;
	int i = 1;
	while (i<v.size()) {
		if (v[i].first) {
			res = max(res, v[i].second.first - tmp);
			tmp = v[i].second.second;
		}
		i++;
	}
	return res;

}

int problem164() {
	vector<int>nums = { 2,8,5,5,3};
	cout << maximumGap(nums) << endl;
	return 0;
}