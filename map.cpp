#include <iostream> 
#include <string> 
#include <map> 
using namespace std; 

int main() { 
 string name; 
 int pop; 

 string states[] = { "Maharashtra", "Bihar", "Uttar Pradesh" }; 
 int pops[] = { 112374333, 104099452, 199812341 }; 
 map<string, int> mapStates; 

 for (int j = 0; j < 3; j++) { 
 name = states[j];  
 pop = pops[j]; 
 mapStates[name] = pop; } 

 cout << "Enter state: ";  
 cin >> name; 

 if (mapStates.find(name) != mapStates.end()) { 
 pop = mapStates[name]; // find population 
 cout << "Population: " << pop << "\n"; 
 } else { 
 cout << "State not found!\n"; } 

 cout << endl; 
 for (const auto& iter : mapStates) { 
 cout << iter.first << ": " << iter.second << "\n"; } 
 return 0;
}