#include <iostream>
#include "sort.hpp"
#include <ctime>
#include <chrono>
#include <algorithm>
using namespace std;

template<typename T, typename Compare>
void std_sort(std::vector<T> &vector, Compare comp = std::less<T>()) {
    std::sort(vector.begin(), vector.end(), comp);
}

int main(int argc, char const *argv[])
{
    // Number of elements in the array
    int size = atoi(argv[1]);
    // Type of sort algorithm to be tested
    int test_type = atoi(argv[2]);
    // Initialize random seed
    srand(time(NULL));
    double total_time = 0;
    for(int i = 0; i < 100; i++){
        // Initialize the array
        vector<int> vec(size);

        // Fill the array with random elements
        for(int i = 0; i < size; i++) vec[i] = rand() % 1000;

            auto start = std::chrono::steady_clock::now();
            
            switch (test_type){
            case 1:
                bubble_sort(vec, std::less<int>());
                break;
            case 2:
                insertion_sort(vec, std::less<int>());
                break;
            case 3:
                selection_sort(vec, std::less<int>());
                break;
            case 4:
                merge_sort(vec, std::less<int>());
                break;
            case 5:
                quick_sort_extra(vec, std::less<int>());
                break;
            case 6:
                quick_sort_inplace(vec, std::less<int>());
                break;
            default:
                std_sort(vec, std::less<int>());
                break;
            }
            auto end = std::chrono::steady_clock::now();
            // cout the time
            chrono::duration<double, std::micro> elapsed_seconds = end-start;
            total_time += elapsed_seconds.count();
    }

    total_time /= 100;
    cout << total_time << "| ";

    return 0;
}
