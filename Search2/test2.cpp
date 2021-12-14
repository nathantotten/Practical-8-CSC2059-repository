#include "List.h"
#include "ListNode.h"
#include <iostream>

using namespace std;

//This will be a recursive binary search as it just works nicely
int binarySearch(List<int>* pList, int first, int last, int key)
{
	// base case - for not found
	if (first > last) return -1;

	// recursive case
	int mid = (first + last) / 2;
	int val = pList->get(mid);
	if (val == key)
		return mid;
	else if (key < val)
		// If the key is before the mid point, then call the function recursively
		//	with the new last value being the midvalue-1 as the index.
		// This moves the search to the left subtree.
		return binarySearch(pList, first, mid - 1, key);
	else
		// If the key is greater than the mid value then the first value becomes the
		//	mid val + 1 to move to the right subtree.
		return binarySearch(pList, mid + 1, last, key);
	// This recursive algorithm will keep auto navigating down the left or right subtree until
	//	the desired value is found
}

int main()
{
	cout << "Input (1) List size (2) key: " << endl;
	int N, key;
	cin >> N >> key;

	// test binarySearch
	List<int>* pList = new List<int>;
	for (int i = 0; i < N; i++)
		pList->insert_end(i);

	cout << "Position of occurence = " << binarySearch(pList, 0, pList->size() - 1, key) << endl;


	return 0;
}