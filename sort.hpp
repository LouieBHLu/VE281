#ifndef VE281P1_SORT_HPP
#define VE281P1_SORT_HPP

#include <vector>

template<typename T, typename Compare>
void bubble_sort(std::vector<T> &vector, Compare comp = std::less<T>()) {
    int len = (int)vector.size();
    for(int i = len - 1; i > 0; i--){
        for(int j = 0; j < i; j++){
            if(comp(vector[j+1],vector[j])){
                std::swap(vector[j], vector[j+1]);
            }
        }
    }
}

template<typename T, typename Compare>
void insertion_sort(std::vector<T> &vector, Compare comp = std::less<T>()) {
    int len = (int)vector.size();
    for(int i = 0; i < len; i++){
        T temp = vector[i];
        int j = i;
        while(j >= 1){
            if(comp(temp, vector[j-1])){
                vector[j] = vector[j-1];
                j--;
            }
            else break;
        }
        vector[j] = temp;
    }
}

template<typename T, typename Compare>
void selection_sort(std::vector<T> &vector, Compare comp = std::less<T>()) {
    int len = (int)vector.size();
    for(int i = 0; i < len - 1; i++){
        int index = i;
        for(int j = i + 1; j < len; j++){
            if(comp(vector[j], vector[index])) index = j;
        }
        if(index != i) std::swap(vector[index], vector[i]);  
    }
}

template<typename T, typename Compare>
void merge(std::vector<T> &vector, int left, int mid, int right, Compare comp = std::less<T>()){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    //create temp array
    //int L[n1], R[n2];
    std::vector<T> L(n1);
    std::vector<T> R(n2);

    //copy data to temp arrays
    for(int i = 0; i < n1; i++) L[i] = vector[left + i];
    for(int j = 0; j < n2; j++) R[j] = vector[mid + 1 + j];
    //merge the temp arrays
    int i = 0;
    int j = 0;
    int k = left;
    while(i < n1 && j < n2){
        if(!comp(R[j], L[i])) vector[k] = L[i++];
        else vector[k] = R[j++];
        k++;
    }
    while(i < n1){
        vector[k] = L[i];
        k++;
        i++;
    }
    while(j < n2){
        vector[k] = R[j];
        j++;
        k++;
    }
}

template<typename T, typename Compare>
void merge_helper(std::vector<T> &vector, int left, int right, Compare comp = std::less<T>()){
    if(left >= right) return;
    int mid = (left + right)/2;
    merge_helper(vector, left, mid, comp);
    merge_helper(vector, mid+1, right, comp);
    merge(vector, left, mid, right, comp);
}

template<typename T, typename Compare>
void merge_sort(std::vector<T> &vector, Compare comp = std::less<T>()) {
    int len = (int)vector.size();
    merge_helper(vector, 0, len-1, comp);
}

template<typename T, typename Compare>
int partition_ex(std::vector<T> &vector, int left, int right, Compare comp = std::less<T>()){
    int rand_index = rand() % (right - left + 1) + left;
    std::swap(vector[left], vector[rand_index]);
    int k = left;
    int j = right;
    std::vector<T> vector2(right - left + 1);

    //sort
    for(int i = left + 1; i <= right; i++){
        if(comp(vector[i], vector[left])){
            vector2[k - left] = vector[i];
            k++;
        }
        else{
            vector2[j - left] = vector[i];
            j--;
        } 
    }
    vector2[k - left] = vector[left];
    //duplicate
    for(int i = left; i <= right; i++){
        vector[i] = vector2[i - left];
    }
    return k;
}

template<typename T, typename Compare>
void quick_sort_helper(std::vector<T> &vector, int left, int right, Compare comp = std::less<T>()){
    if(left >= right) return;
    int pivotat;
    pivotat = partition_ex(vector, left, right, comp);
    quick_sort_helper(vector, left, pivotat - 1, comp);
    quick_sort_helper(vector, pivotat + 1, right, comp);
}

template<typename T, typename Compare>
void quick_sort_extra(std::vector<T> &vector, Compare comp = std::less<T>()) {
    int len = (int)vector.size();
    quick_sort_helper(vector, 0, len-1, comp);
}

template<typename T, typename Compare>
int partition_in_place(std::vector<T> &vector, int left, int right, Compare comp = std::less<T>()){
    int len = right - left + 1;
    int pivotat = rand() % len + left;
    std::swap(vector[pivotat], vector[left]);
    int i = left + 1;
    int j = right;
    while(true){
        while(comp(vector[i], vector[left]) && i <= right) i++;
        while(!comp(vector[j], vector[left]) && j > left) j--;
        if(i < j) std::swap(vector[i], vector[j]);
        else break;
    }
    std::swap(vector[left], vector[j]);
    return j;
}

template<typename T, typename Compare>
void quick_sort_helper_in_place(std::vector<T> &vector, int left, int right, Compare comp = std::less<T>()){
    if(left >= right) return;
    int pivotat;
    pivotat = partition_in_place(vector, left, right, comp);

    quick_sort_helper_in_place(vector, left, pivotat - 1, comp);
    quick_sort_helper_in_place(vector, pivotat + 1, right, comp);
}

template<typename T, typename Compare>
void quick_sort_inplace(std::vector<T> &vector, Compare comp = std::less<T>()){
    int len = (int)vector.size();
    quick_sort_helper_in_place(vector, 0, len-1 ,comp);
}

#endif //VE281P1_SORT_HPP
