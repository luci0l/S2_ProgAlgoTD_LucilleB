#include <iostream>
#include <unordered_set>
#include <fstream>
#include <sstream>


enum class Direction {
  Haut,
  Droite,
  Bas, 
  Gauche
};


struct Position{
  int x; 
  int y;

  bool operator==(Position const& other) const{   //Compare les valeurs des positions
    return x==other.x && y==other.y;
  }

  Position operator+(Position const& other) {
      return {x + other.x, y + other.y};
  }

  void operator +=(Position& other) { //addition de coordonnées
    *this = *this + other;
  }

  Position deplacement(Direction dir){
    if (dir == Direction::Haut) {
      return Position{0, -1};
    }
    else if (dir == Direction::Droite){
      return Position {1,0};
    }
    else if (dir == Direction::Bas){
      return Position{0,1};
    }
    else if (dir == Direction::Gauche){
      return Position{-1,0};
    }
    else {
      return Position{0,0};
    }
  }

  Position operator+(Direction const& dir){
    Position newpos;
    newpos = *this + deplacement(dir);
    return newpos;
  }

  void operator+=(Direction const& dir){
    *this = *this + dir;
  }
};

std::ostream& operator<<(std::ostream& os, Position const& pos) { //afficher coordonnées
    return os << '(' << pos.x << ", " << pos.y << ')';
}


Direction turn_right(Direction const& dir){
  switch(dir) {
    case Direction::Haut:
      return Direction::Droite;
    case Direction::Droite:
      return Direction::Bas;
    case Direction::Bas:
      return Direction::Gauche;
    case Direction::Gauche:
      return Direction::Haut;
  }
}




namespace std{
  template<>struct hash<Position>{
    std::size_t operator()(const Position& pos) const{
      std::size_t Hash = 31;
      return pos.x *Hash +pos.y;
    }
  };
}

//Question 2 : Lecture de la carte

struct Input_Map{
  std::unordered_set<Position> obstacle{};
  Position pos_garde;
  Direction dir_garde;
  int largeur{0};
  int hauteur{0};
};


Input_Map parse_input(std::istream& input_stream){
  Input_Map map;
  
  int row {0};

  for (std::string line{}; std::getline(input_stream, line, '\n') and line !="";){
    for( int col {0}; col < static_cast<int>(line.size()); col ++){
      char c {line[col]};

      if(c=='#'){
        map.obstacle.insert(Position{col, row});
      }
      else if (c =='^'){
        map.pos_garde = Position{col, row};
        map.dir_garde = Direction::Haut;
      }
      else if (c =='>'){
        map.pos_garde = Position{col, row};
        map.dir_garde = Direction::Droite;
      }
      else if (c == 'v'){
        map.pos_garde = Position{col, row};
        map.dir_garde = Direction::Bas;
      }
      else if (c == '<'){
        map.pos_garde = Position{col, row};
        map.dir_garde = Direction::Gauche;
      }
    }
    map.largeur =static_cast<int>(line.size());
    row++;
    map.hauteur = row;
  }
  return map;
}



bool on_the_map(Position const& pos, int largeur, int hauteur) {
    return pos.x >= 0 && pos.x < largeur && pos.y >= 0 && pos.y < hauteur;
}

struct WalkResult {
Position final_position;
size_t steps_taken;
std::unordered_set<Position> visited_positions;
};


WalkResult simulation(Input_Map const& map, int largeur, int hauteur) {
  WalkResult result;
  Position current_position = map.pos_garde;
  Direction current_direction = map.dir_garde;

  while(on_the_map(current_position, largeur, hauteur)){//garde encore sur la map
    result.visited_positions.insert(current_position); //enregistrer la position actuelle

    Position next {current_position + current_direction}; //calculer la position suivante
  
  if (map.obstacle.count(next)){
    current_direction = turn_right(current_direction); //tourner à droite
  }
  else{
    current_position = next; //pas d'obstacle alors on avancer
    result.steps_taken++;
  }

  }

  result.final_position = current_position;
  return result;
}


// int main() {
//     std::ifstream file { "map_test.txt" };
//       if (!file) {
//         std::cout << "Erreur : fichier introuvable " << std::endl;
//         return 1;
//     }
//     Input_Map map { parse_input(file) };

//     WalkResult resultat { simulation(map, 10, 10) };

//     std::cout << "Position finale : " << resultat.final_position << std::endl;
//     std::cout << "Pas effectués : " << resultat.steps_taken << std::endl;
//     std::cout << "Cases visitées : " << resultat.visited_positions.size() << std::endl;
// }
   


int main() {
    std::istringstream carte { //je n'arrive pas à faire fonctionner la lecture du fichier alors j'ai mis la carte dans une string
        "....#.....\n"
        ".........#\n"
        "..........\n"
        "..#.......\n"
        ".......#..\n"
        "..........\n"
        ".#..^.....\n"
        "........#.\n"
        "#.........\n"
        "......#...\n"
    };



    Input_Map map { parse_input(carte) };
    WalkResult resultat { simulation(map, map.largeur, map.hauteur) };

    std::cout << "Position finale : " << resultat.final_position << std::endl;
    std::cout << "Pas effectués : " << resultat.steps_taken << std::endl;
    std::cout << "Cases visitées : " << resultat.visited_positions.size() << std::endl;
}

//Position finale : (7, 10)
//Pas effectués : 45
//Cases visitées : 41