#include <iostream>
#include <vector>  // For std::vector
#include <algorithm> // For std::sort
using namespace std;

int main() {
    // Create a vector of integers
    std::vector<int> vec;

    // 1. push_back(): Adding elements at the end
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    
    std::cout << "Vector after push_back: ";
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // 2. pop_back(): Remove the last element
    vec.pop_back();
    std::cout << "Vector after pop_back: ";
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // 3. size(): Get the size of the vector
    std::cout << "Size of the vector: " << vec.size() << std::endl;

    // 4. at(): Access element at a specific index with bounds checking
    std::cout << "Element at index 2: " << vec.at(2) << std::endl;

    // 5. front() and back(): Access the first and last elements
    std::cout << "Front element: " << vec.front() << std::endl;
    std::cout << "Back element: " << vec.back() << std::endl;

    // 6. insert(): Insert element at a specific position
    vec.insert(vec.begin() + 1, 15);
    std::cout << "Vector after inserting 15 at index 1: ";
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // 7. erase(): Erase element from a specific position
    vec.erase(vec.begin() + 2);
    std::cout << "Vector after erasing element at index 2: ";
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // 8. clear(): Remove all elements
    vec.clear();
    std::cout << "Vector after clear(), size: " << vec.size() << std::endl;

    // Re-inserting elements to demonstrate other functions
    vec.push_back(50);
    vec.push_back(60);
    vec.push_back(70);

    // 9. resize(): Resize the vector
    vec.resize(5, 100);  // Resize to 5, filling new elements with 100
    std::cout << "Vector after resize to 5 with default 100: ";
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // 10. capacity(): Show the capacity (allocated memory) of the vector
    std::cout << "Vector capacity: " << vec.capacity() << std::endl;

    // 11. reserve(): Request a minimum capacity
    vec.reserve(10);
    std::cout << "Vector capacity after reserve(10): " << vec.capacity() << std::endl;

    // 12. sort(): Sorting the vector elements (using algorithm header)
    std::vector<int> unsortedVec = {42, 15, 99, 23, 8};
    std::cout << "Unsorted vector: ";
    for (int i = 0; i < unsortedVec.size(); i++) {
        std::cout << unsortedVec[i] << " ";
    }
    std::cout << std::endl;

    std::sort(unsortedVec.begin(), unsortedVec.end());  // Sort in ascending order
    std::cout << "Sorted vector: ";
    for (int i = 0; i < unsortedVec.size(); i++) {
        std::cout << unsortedVec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
