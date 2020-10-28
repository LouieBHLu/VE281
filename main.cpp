#include <iostream>
#include "sort.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> vec(10);
    for(int i = 0; i < 10; i++) vec[i] = rand() % 10000;
    vector<int> ori(vec);
    vector<int> vec_big(187);
    for(int i = 0; i < 187; i++) vec_big[i] = i;

    bubble_sort(vec, less<int>());
    for(int i = 0; i < 10; i++) vec[i] = ori[i];

    selection_sort(vec, less<int>());
    for(int i = 0; i < 10; i++) vec[i] = ori[i];

    insertion_sort(vec, less<int>());
    for(int i = 0; i < 10; i++) vec[i] = ori[i];

    merge_sort(vec, less<int>());
    for(int i = 0; i < 10; i++) vec[i] = ori[i];
    
    quick_sort_inplace(vec_big, less<int>());
    for(int i = 0; i < 187; i++) vec_big[i] = i;

    quick_sort_extra(vec_big, less<int>());
    for(int i = 0; i < 187; i++) vec_big[i] = i;



    return 0;
}
