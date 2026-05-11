# Projet OSM : Algorithme de Dijkstra

## 1. Identifier les structures

### WeightedGraph

Les fleches entre les noeuds, store id et arretes, c'est une liste d'adjacence.
Stock les ids et les poids des arretes mais pas les positions.

### PositionedGraph

Stock les positions des nodes pour chaque id de nodes

## 2. Expliquer le rôle des modules

### Extraction OSM

.\osmGraph.exe extract ./data/test.osm ./data/ext_graph

Sert à lire un fichier OSM pour exporter une représentation de graphe.
La commande prend 2 arguments :

- Input Path : chemin du ficher osm à utiliser (test.osm)
- Output Path : chemin de l'emplacement du fichier msgpack de sortie (ext_graph)

### Simplification

.\osmGraph.exe simplify ./data/ext_graph

Simplifie un graph en enlevant les noeuds et les arretes "inutiles" pour réduire la taille du graphe et le rendre plus efficace.
La commande prend 1 argument :

- Input Path : chemin du fichier du graphe msgpack à utiliser

### Visualisation

\osmGraph.exe visualize ./data/ext_graph

Permet de visualisez le grape d'un ficher msgpack

Positional arguments:

- Input Path to the input graph msgpack file [required]

## 3. Explication des étapes de simplification

- keep_only_largest_connected_component(graph); : Trouve tous les noeuds connectés à la plus grande composante et supprime ceux qui n'y sont pas liés

- remove_small_ending_edge(graph, 10.0); : Suprrime les noeuds avec une seule arête et une distance inferieure à 10, elles sont inutiles et alourdissent le graphe.

- remove_degree_two_nodes_by_angle_threshold(graph, 30); : Supprime un noeud entra 2 voisins si l'angle de leur 2 arêtes est proche de 180. Dans ce cas, on supprime le noeud et on remplace par une arête directe et on additionne les poids.

- group_nodes_by_connection_depth_and_proximity(graph, 10.0, 6); : Groupe les noeuds qui sont très proches.
