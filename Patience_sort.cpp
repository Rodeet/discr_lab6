#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

std::vector<std::stack<int>> piles;
std::vector<int> answer;

void fillPiles(std::vector<int>& data) {
	for (int i = 0; i < data.size(); i++) {
		int left = 0, right = piles.size() - 1;
		int middle;
		while (left <= right) {
			middle = (left + right) / 2;
			if (data[i] > piles[middle].top())
				left = middle + 1;
			else
				right = middle - 1;
		}
		if (left >= piles.size())
			piles.resize(piles.size() + 1);
		piles[left].push(data[i]);
	}
}

void sort(std::vector<int>& data) {
	for (int k = 0; k < data.size(); k++) {
		int parentID = 0;
		answer[k] = piles[parentID].top();
		piles[parentID].pop();
		if (piles[parentID].empty()) {
			std::swap(piles[parentID], piles[piles.size() - 1]);
			piles.pop_back();
		}
		while (2 * parentID + 1 < piles.size()) {
			int left = 2 * parentID + 1;
			int right = 2 * parentID + 2;
			int minChild = left;
			if (right < piles.size() && piles[right].top() < piles[left].top())
				minChild = right;
			if (piles[parentID].top() <= piles[minChild].top())
				break;
			std::swap(piles[parentID], piles[minChild]);
			parentID = minChild;
		}
	}
}

int main() {
	std::vector<int> arr = { -4,5,-3,-5,6,10,-9 };
	answer.resize(arr.size());
	fillPiles(arr);
	std::cout << "Original array: ";
	for (auto var : arr)
		std::cout << var << " ";
	std::vector<std::stack<int>> cp_p(piles);
	std::cout << "\n\nStack`s array:\n";
	for (int i = 0; i < cp_p.size(); i++) {
		while (!cp_p[i].empty()) {
			std::cout << cp_p[i].top() << " ";
			cp_p[i].pop();
		}
		std::cout << "\n";
	}
	sort(arr);
	std::cout << "\n\nSorted array: ";
	for (auto var : answer)
		std::cout << var << " ";
}
