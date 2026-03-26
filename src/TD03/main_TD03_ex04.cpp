#include <vector>
#include <algorithm>
#include <iostream>


void search(std::vector<int> const&vec, int value){
  size_t left { 0 };
  size_t right = vec.size() - 1;

  while(left <= right){
    size_t middle = (left + right) /2;

    if(vec[middle] == value){

    }
    else if (vec[middle] < value){

    }
    else if (vec[middle]> value){

    }
   
  }
  
}

int main(){
  
}