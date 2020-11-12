#include "hashtable.hpp"
#include <chrono>
using namespace std;

int main(int argc, char const *argv[])
{
    
    size_t bucketNum = 10;
    HashTable<int, char> H1(bucketNum);
    cout << H1.bucketSize() << endl;
    
    int key = 20;
    char value = 'a';
    if(H1.insert(20, 'a')) cout << "insert successfully!" << endl;
    cout << H1[20] << endl;
    cout << H1[10] << endl;
    //for(auto it = H1.begin(); it != H1.end(); ++it) cout << it->first << " " << it->second << endl;
    if(H1.insert(30, 'b')) cout << "insert successfully!" << endl;
    for(auto it = H1.begin(); it != H1.end(); ++it) cout << it->first << " " << it->second << endl;
    if(H1.insert(40, 'c')) cout << "insert successfully!" << endl;
    if(H1.insert(50, 'd')) cout << "insert successfully!" << endl;
    cout << H1.loadFactor() << endl;
    if(H1.insert(60, 'e')) cout << "insert successfully!" << endl;
    cout << H1.bucketSize() << endl;
    // HashTable<int, char> H2(H1);
    // if(H2.insert(40, 'c')) cout << "insert successfully!" << endl;
    // for(auto it = H2.begin(); it != H2.end(); ++it) cout << it->first << " " << it->second << endl;
    
    // HashTable<int, char> H3;
    // cout << H3.bucketSize() << endl;
    // if(H3.insert(21, 'b')) cout << "insert successfully!" << endl;
    // H3 = H2;
    // cout << H3.bucketSize() << endl;
    //for(auto it = H3.begin(); it != H3.end(); ++it) cout << it->first << " " << it->second << endl;

    
 
    // if(H1.erase(20)){
    // }

    // if(H1.erase(10)){
    // }
    return 0;
}


