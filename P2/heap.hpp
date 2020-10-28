#ifndef HEAP_HPP
#define HEAP_HPP

#include <vector>
using namespace std;

void percolate_down(int heap[], int id, int size){
    for(int j = 2 * id; j <= size; j = 2 * id){
        if(j < size && heap[j] > heap[j+1]) j++;
        if(heap[id] < heap[j]) break;
        swap(heap[id], heap[j]);
        id = j;
    }
}

void percolate_up(int heap[], int id, int size){
    while(id > 1 && heap[id/2] > heap[id]){
        swap(heap[id], heap[id/2]);
        id /= 2;
    }
}
#endif