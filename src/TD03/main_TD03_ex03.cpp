#include <vector>
#include <cstdlib>
#include <algorithm>
#include "ScopedTimer.hpp"

//copié collé des exos précédents, faire un .hpp serait plus propre
void bubble_sort(std::vector<int> & vec){
int n = vec.size();
for (int i=0; i<n; i++) {
  for(int j=0; j<n-i-1; j++) {
    if(vec[j]> vec[j+1]){
      std::swap(vec[j], vec[j+1]);
      }
    }
  }
}


size_t quick_sort_partition(std::vector<int> & vec, size_t left, size_t right){
int pivot = vec[right];
size_t i = left;

for(size_t j = left ; j< right ; j++){
if(vec[j] < pivot){
std::swap(vec[i], vec[j]); //ici, on place si le chiffre est plus petit que le pivoit à gauche
i++;
    }
}

std::swap(vec[i], vec[right]);
return i;
}

void quick_sort(std::vector<int> & vec, size_t const left, size_t const right){
  if (left >= right) {
    return;
  }
  size_t index_pivot = quick_sort_partition(vec, left, right); //Recursion

  if (index_pivot > 0) { // evite les crashs si index_pivot == 0
  
    quick_sort(vec, left, index_pivot -1); //plus petit que pivot
    }

    quick_sort(vec, index_pivot + 1, right ); //plus grand que pivot
}

void quick_sort(std::vector<int> & vec) {
    quick_sort(vec, 0, vec.size() - 1);
}




std::vector<int> generate_random_vector(size_t const size, int const max = 100) {
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}

std::vector<int> array = generate_random_vector(1000);

int main(){
  
{
ScopedTimer timer("bubble sort");
bubble_sort(array);
}

{
ScopedTimer timer("quick sort");
quick_sort(array);
}

{
ScopedTimer timer("std::sort");
std::sort(array.begin(), array.end());
}
// à corriger : les 3 tris sont appliqués sur le meme tableau, je devrait en  faire 3 différents aléatoires ?
}
