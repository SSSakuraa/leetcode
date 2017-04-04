#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

// Number3
// Given a string, find the length of the longest substring without repeating characters.
// Examples:
// Given "abcabcbb", the answer is "abc", which the length is 3.
// Given "bbbbb", the answer is "b", with the length of 1.
// Given "pwwkew", the answer is "wke", with the length of 3. 
// Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

int lengthOfLongestSubstring(string s) {
	map<char, int> charIndex;
	int begin = 0;
	int res = 0;
	int index = 0;
	for (; index < (int)s.size(); index++) {
		pair<map<char, int>::iterator, bool> ret = charIndex.insert(pair<char, int>(s[index], index));
		if (!ret.second) {
			int tmp = ret.first->second;
			if (tmp >= begin) {
				res = max(res, index - begin);
				begin = max(tmp, begin) + 1;
			}
			ret.first->second = index;
		}
	}
	res = max(res, index - begin);
	return 	res;

}

int problem3() {
	string s = "asdfoirjtfiojdsiufhqoinguqeroirjkjhsfqajewign";
	int i = lengthOfLongestSubstring(s);
	cout << i << endl;
	return 0;
}