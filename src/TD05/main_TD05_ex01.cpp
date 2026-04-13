 #include <iostream>



size_t folding_string_hash(std::string const& s, size_t max){
   size_t hash{0};
 
  for(char c: s){
    hash += c;
    hash = hash%max;
  }

   return hash;
}


size_t fold_string_ordered_hash(std::string const& s, size_t max){
  size_t hash{0};
  for(size_t i{0}; i< s.size(); i++){
    hash += s[i] * (i+1);
    hash = hash%max;
  }

  return hash;
}


// 1 Haching Simple 

// size_t folding_string_hash(std::string const& s, size_t max){
//   size_t hash{0};
// for(size_t i{0}; i< s.size(); i++){
//   hash += s[i];
//   hash %=max;
// }

// return hash;
// }
int main() {
    std::cout << folding_string_hash("abc", 1024) << std::endl;
    std::cout << folding_string_hash("cba", 1024) << std::endl;
    std::cout << fold_string_ordered_hash("abc", 1024) << std::endl;
    std::cout << fold_string_ordered_hash("cba", 1024) << std::endl;
   
}

