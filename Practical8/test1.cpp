#include <vector>
#include <string>
#include <iostream>

using namespace std;

// find index of 1st number not in [lower, upper]
int find_first_not_in_range(int* pi, int N, int lower, int upper)
{
	for (int n = 0; n < N; n++)
		if (!(pi[n] >= lower && pi[n] <= upper))
			return n;
	return -1;
}

int main()
{
	return 0;
}

// Test find_first_not_in_range
int main1()
{

	cout << "Type: (1) array size N (2) lower bound (3) upper bound " << "\n";
	int N, L, U;
	cin >> N >> L >> U;

	int* pi = new int[N];

	if (pi) {
		// create the array with N random numbers in the range 0-100
		for (int i = 0; i < N; i++)
			pi[i] = rand() % 101;

		// print the array
		for (int i = 0; i < N; i++)
			cout << pi[i] << " ";
		cout << "\n";
		
		// search the array for the number
		cout << "The 1st number not in [" << L << ", " << U << "] is found at "
			<< find_first_not_in_range(pi, N, L, U) << "\n";

	}
	delete[] pi;

	// complexity statement
	cout << "The complexity of find_first_not_in_range is " << "O(N)" << "\n";

	return 0;
}