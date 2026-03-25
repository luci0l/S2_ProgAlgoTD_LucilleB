#include <vector>
#include <algorithm>
#include <iostream>
bool is_sorted(std::vector<int> const& vec) { return std::is_sorted(vec.begin(), vec.end()); }



void bubble_sort(std::vector<int> & vec){
int n = vec.size();
for (int i=0; i<n; i++) {
  for(int j=0; j<n-i-1; j++) { //-i pour les éléments déjà triés
    if(vec[j]> vec[j+1]){
      std::swap(vec[j], vec[j+1]);
 }

    //std::swap(vec[0], vec[10]);
  }
}
}

int main(){

std::vector<int> array {1, 3, 2, 5, 4, 3, 7, 6, 9};
bubble_sort(array);
if (is_sorted(array)) {
    std::cout << "Le tableau est trié" << std::endl;
} else {
    std::cout << "Le tableau n'est pas trié" << std::endl;
}
}