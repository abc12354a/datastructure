#include <iostream>
#include <vector>
#include<algorithm>
#include<math.h>
#define MAX 65535
using namespace std;
int islegal(vector<int> node, int begin, int end) {
	if (end - begin == 0) {
		return 1;
	}
	else if (node[begin] == 0 && node[end] == 0) {
		return 0;
	}
	else if (node[end] == 0) {
		return 1;
	}
	else if (node[begin] == 0) {
		return 1;
	}
	else {
		return end - begin+1;
	}
}
int main() {
	vector<int> a;
	char c;
	int total = 0;
	while ((c = cin.get()) != '\n') {
		a.push_back(int(c - 48));
	}
	if (a.size() == 1) {
		std::cout << "1";
	}
	else if (a[0] ==0 && a[a.size() - 1] == 0) {
		std::cout << "0";
	}
	else if (int(a[0]) == 0) {
		std::cout << "2";
	}
	else {
		for (int i = 1; i < a.size(); i++) {
			total += islegal(a, 0, i-1)*islegal(a, i, a.size() - 1);
		}
		std::cout << total;
	}

	system("pause");
	return 0;
}