#include <vector>
#include <algorithm>
#include <iostream>

bool is_sorted(std::vector<int> const& vec) { return std::is_sorted(vec.begin(), vec.end())}
  

size_t quick_sort_partition(std::vector<int> & vec, size_t left, size_t right){
int pivot = vec[right];
size_t i = vec[left];

for(size_t j = left ; j> le)

}



void quick_sort(std::vector<int> & vec, size_t const left, size_t const right){
  
}
void quick_sort(std::vector<int> & vec) {
    quick_sort(vec, 0, vec.size() - 1);
}




int main(){

std::vector<int> array {1, 3, 2, 5, 4, 3, 7, 6, 9};
//bubble_sort(array);
if (is_sorted(array)) {
    std::cout << "Le tableau est trié" << std::endl;
} else {
    std::cout << "Le tableau n'est pas trié" << std::endl;
}
}
