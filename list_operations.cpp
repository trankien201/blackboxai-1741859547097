#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class NumberList {
private:
    vector<int> numbers;

public:
    // Initialize empty list
    NumberList() {}

    // Insert number x after position i
    void insertAfter(int i, int x) {
        if (i == 0) {
            // Insert at beginning
            numbers.insert(numbers.begin(), x);
        }
        else if (i <= numbers.size()) {
            // Insert after position i
            numbers.insert(numbers.begin() + i, x);
        }
    }

    // Find minimum element between positions i and j
    int findMin(int i, int j) {
        if (i > j || i < 1 || j > numbers.size()) {
            return -1; // Invalid range
        }
        
        // Convert to 0-based indexing
        i--;
        j--;
        
        return *min_element(numbers.begin() + i, numbers.begin() + j + 1);
    }

    // Print current list
    void printList() {
        cout << "Current list: ";
        for (int num : numbers) {
            cout << num << " ";
        }
        cout << endl;
    }
};

int main() {
    NumberList list;
    
    // Test cases from the table
    cout << "Initial state: Empty list" << endl;
    
    list.insertAfter(0, 5);
    cout << "After +0 5: ";
    list.printList();
    
    list.insertAfter(1, 3);
    cout << "After +1 3: ";
    list.printList();
    
    list.insertAfter(1, 4);
    cout << "After +1 4: ";
    list.printList();
    
    cout << "?1 2 result: " << list.findMin(1, 2) << endl;
    
    list.insertAfter(0, 2);
    cout << "After +0 2: ";
    list.printList();
    
    cout << "?2 4 result: " << list.findMin(2, 4) << endl;
    
    list.insertAfter(4, 1);
    cout << "After +4 1: ";
    list.printList();
    
    cout << "?3 5 result: " << list.findMin(3, 5) << endl;

    return 0;
}
