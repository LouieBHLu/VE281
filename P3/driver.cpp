#include "kdtree.hpp"
#include <iostream>
using namespace std;
typedef tuple<int, int> Key;
typedef char Value;

int main(int argc, char const *argv[])
{

    int i = 0;
    vector<pair<Key,Value>> v(6);
    v[1].first = {1,5};
    v[0].first = {2,4};
    v[4].first = {3,3};
    v[2].first = {4,2};
    v[3].first = {5,1};
    v[5].first = {1,5};
    v[0].second = 'a';
    v[1].second = 'b';
    v[2].second = 'c';
    v[3].second = 'd';
    v[4].second = 'e';
    v[5].second = 'f';

    // Test constructor
    KDTree<Key,Value> t1(v);
    for(auto it = t1.begin(); it != t1.end(); ++it){
        cout << it->second << endl;
    }

    // Test --
    auto it_end = t1.end();
    it_end--;
    cout << it_end->second << endl;
    it_end--;
    cout << it_end->second << endl;
    it_end--;
    cout << it_end->second << endl;
    it_end--;
    cout << it_end->second << endl;
    it_end--;
    cout << it_end->second << endl;
    
    // Test find
    Key k = {1,5};
    Key k_new = {-1,5}; 
    auto it_modify = t1.find(k);
    cout << it_modify->second << endl;
    t1.insert(k, 'F');
    for(auto it = t1.begin(); it != t1.end(); ++it){
        cout << it->second << endl;
    }
    t1.insert(k_new, 'g');
    for(auto it = t1.begin(); it != t1.end(); ++it){
        cout << it->second << endl;
    }

    // Test findmin
    auto it_min_x = t1.findMin<0>();
    cout << it_min_x->second << endl;

    auto it_min_y = t1.findMin<1>();
    cout << it_min_y->second << endl;

    // Test findmax
    auto it_max_x = t1.findMax<0>();
    cout << it_max_x->second << endl;

    auto it_max_y = t1.findMax<1>();
    cout << it_max_y->second << endl;

    // Test copy constructor
    KDTree<Key,Value> t1_copy(t1); 

    for(auto it = t1.begin(); it != t1.end(); ++it){
        cout << it->second << endl;
    }

    for(auto it = t1_copy.begin(); it != t1_copy.end(); ++it){
        cout << it->second << endl;
    }

    // Test assignment operator
    KDTree<Key,Value> t2;
    t2 = t1;

    // // Test erase
    // t1.erase(k_new);

    // for(auto it = t1.begin(); it != t1.end(); ++it){
    //     cout << it->second << endl;
    // }

    // t1.erase({3,3});

    // for(auto it = t1.begin(); it != t1.end(); ++it){
    //     cout << it->second << endl;
    // }
  






    return 0;
}

