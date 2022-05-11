#include <iostream>
#include <vector>
using namespace std;

vector<int> MaxSubSum(const vector<int>& a) {
	int currMS = a[0], maxMS = currMS;
	int start = 0;
	int end = 0;
	for (int i = 1; i < a.size(); i++)
	{
		currMS = max(currMS + a[i], a[i]);
		maxMS = max(maxMS, currMS);

		if (maxMS == currMS) {
			end = i;
		}
	}

	int reverseSum = a[end];
	for (int i = end - 1; i >= 0; i--) {
		reverseSum += a[i];
		if (reverseSum == maxMS) {
			start = i;
			break;
		}
	}

	return { maxMS, start, end };
}

int main()
{
	//Test Case #1: a = { -2, 11, -4, 13, -5, -2 }
	vector<int> test1 = { -2, 11, -4, 13, -5, -2 };
	vector<int> test2 = { 20, 20, 20, 20, -10, -10, -10 };
	vector<int> test3 = { -10, -10, -10, 20, 20, 20 };
	vector<int> test4 = { 10, 5, -15, 17, -4, 15 };

	MaxSubSum(test1);
	MaxSubSum(test2);
	MaxSubSum(test3);
	MaxSubSum(test4);

	std::cout << "Test Case #1 results: " << "{" << test1[0] << ", " << test1[1] << ", " << test1[2] << "}" << "\n";
	std::cout << "Test Case #2 results: " << "{" << test2[0] << ", " << test2[1] << ", " << test2[2] << "}" << "\n";
	std::cout << "Test Case #3 results: " << "{" << test3[0] << ", " << test3[1] << ", " << test3[2] << "}" << "\n";
	std::cout << "Test Case #4 results: " << "{" << test4[0] << ", " << test4[1] << ", " << test4[2] << "}" << "\n";
}

