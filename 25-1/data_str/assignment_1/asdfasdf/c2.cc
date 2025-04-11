#include <iostream>
#include <vector>

char kthCharacter(long long k, std::vector<int>& operations) {
  // TODO: Implement
	int changes = 0; // shows how many does 'a' have to change
	long long length = power2(operations.size());

	while (!operations.empty()) {
		length /= 2;
		int elem = getBackAndPop(operations);
		char whichPart = frontOrBack(k, power2(operations.size()));

		if ((elem == 1) && (whichPart == 'b')) {
			changes++;
		}

		long long threshold = length / 2;
		if (k > threshold) {
			k -= threshold;
		}
	}

	// lower case alphabet : 97 ~ 122 in ascii code
	changes = 97 + (changes % 26);
	char resultChar = (char)changes;
  return resultChar;
}

char frontOrBack(long long k, long long length) {
	// k : kth
	// length : length of the string
	length /= 2;
	if (k <= length) {
		return 'f';
	} else {
		return 'b';
	}
}

int getBackAndPop(std::vector<int>& vec) {
	if (!vec.empty()) {
		int back = vec.back();	
		vec.pop_back();
		return back;
	} else {
		return -1; // error sign
	}
}

long long power2(int exp) {
	long long result = 1;
	long long base = 2;

	while (exp > 0) {
		if (exp % 2 == 1) {
			result *= base;
			exp--;
		} else {
			base *= 2;
			exp /= 2;
		}
	}
	return result;
}