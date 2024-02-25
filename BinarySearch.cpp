/*Binary Search allows us to find a value in an ordered list
By Nicolas Coneo*/
#include <iostream>
#include <vector>
#include <numeric>

int binarySearch (std::vector<int> myInt, int toFind);

int main (int argc, char* argv[]) {

    int sizeOfVector = 100;

    std::vector<int> myList(sizeOfVector);

    int input;

    // Populate myInt with even numbers.
    // TO-DO, populate with prime numbers.
    for (int i = 0; i < myList.size(); i++) {
        myList[i] = i * 2;
    }

    std::cout << "Please enter a number to find" << std::endl;

    std::cin >> input;

    int result = binarySearch (myList, input);

    if (result > 0 ) {
        std::cout << input << " is at myList[ " << result << " ]" << std::endl;
    } 
    else {
        std::cout << input << " was not found on the list" << std::endl;
    }

}

// Returns the index of the element if found, else it returns -1.
int binarySearch (std::vector<int> myIntList, int toFind) {

    int left = 0;
    int right = myIntList.size();
    int center = right / 2;

    bool found = false;


    while (left < center && center < right) {
        
                // We found the number.
        if (myIntList[center] == toFind) {
            found = true;
            break;
        }
        // toFind is to the left. Move to the left.
        else if (myIntList[center] > toFind) {
            right = center;    
        }
        // toFind is to the right. Move to the right.
        else {
            left = center;
        }

        // Same update of the center for both move left or right.
        center = left + ((right - left) / 2);
    }

    if (!found) {
        center = -1;
    }

    return center;
}