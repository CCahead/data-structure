// C++ Program to Find All Occurrences of an Element in a 
// Vector 
#include <algorithm> 
#include <iostream> 
#include <vector> 

using namespace std; 

int main() 
{ 
	// Initialize a vector array 
	vector<int> arr = { 2, 3, 2, 1, 5, 4, 2 }; 

	// Element to search 
	int element = 2; 

	// Find the first occurrence of the element in the 
	// vector 
	auto it = find(arr.begin(), arr.end(), element); 

	// Check if the element was found 
	cout << "The element " << element 
		<< " occurred at indices: "; 
	while (it != arr.end()) { 
		// Print the index of the element 
		cout << it - arr.begin() << ", "; 
		// Search for the next occurrence and keeping 
		// beggining of the range after the currenly found 
		// occurence to avoid infinite loop 
		it = find(it + 1, arr.end(), element); 
	} 
	cout << endl; 

	return 0; 
}
