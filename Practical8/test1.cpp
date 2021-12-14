#include <vector>
#include <string>
#include <iostream>

using namespace std;

//This is all basic and frankly kinda shitty linear searching on UNSORTED integer arrays.
// No fancy tomfoolery here - just slow and annoying code to show a bad example (:

// find index of 1st number not in [lower, upper]
int find_first_not_in_range(int* pi, int N, int lower, int upper)
{
	for (int n = 0; n < N; n++)
		if (!(pi[n] >= lower && pi[n] <= upper))
			return n;
	return -1;
}

void print_duplicate(int* pi1, int N1, int* pi2, int N2)
{
	// For each index up to the size of pi1
	for (int i = 0; i < N1; i++) {
		// set found to false
		bool found = false;
		// check each item in pi2
		for (int j = 0; j < N2; j++) {
			// if the item at i in pi1 is equal to the item at j in pi2
			if (pi1[i] == pi2[j]) {
				// set found = true
				found = true;
				// break out of this loop and go back to searching
				break;
			}
		}
		// if found is true at the end of the first for loop
		// output the data at that final position.
		if (found)
			cout << pi1[i] << endl;
	}
}

// test print_duplicate
int main()
{

	// Get the size of each array from the user
	cout << "Type N1, N2" << endl;
	int N1, N2;
	cin >> N1 >> N2;

	// create the two arrays with the provided sizes
	int* pi1 = new int[N1];
	int* pi2 = new int[N2];

	// So long as pi1 and pi2 are not null/they exist
	if (pi1 && pi2) {
		// initialise pi1 with random values 0-10000 for i = 0 up to N1
		for (int i = 0; i < N1; i++)
			pi1[i] = rand() % 10000;
		// repeat the above step for pi2
		for (int i = 0; i < N2; i++)
			pi2[i] = rand() % 10000;
		// Call the function to display all duplicate values (if there are any)
		print_duplicate(pi1, N1, pi2, N2);
	}

	// Free up memory used by the array pointers
	delete[] pi1;
	delete[] pi2;

	cout << "The complexity of print_duplicate is " << "O(N1 * N2)" << endl;

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