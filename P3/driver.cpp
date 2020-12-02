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
    KDTree<Key,Value> t1(v);
    for(auto it = t1.begin(); it != t1.end(); ++it){
        cout << it->second << endl;
    }
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

    auto it_min_x = t1.findMin<0>();
    cout << it_min_x->second << endl;

    auto it_min_y = t1.findMin<1>();
    cout << it_min_y->second << endl;



    return 0;
}

