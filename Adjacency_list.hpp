#include "Edges.hpp"
#include <iostream>
#include <vector>
#include "Successor.hpp"

class Adgency_list {

    public:
        int V; // Number of vertices
        std::vector<succ>* list; // Array of edges

        Adgency_list(int V) {
            this->V = V;
            list = new std::vector<succ>[V];
        }

        ~Adgency_list() {
            delete[] list;
        }

        void add_edge(Edges &edge) {
            list[edge.x].push_back(succ(edge.y, edge.w));

        }

        void add_edge(int x, int y, int weight) {
            list[x].push_back(succ(y, weight));
        }

      

        void display_adjacency_list(){
            for (int i = 0; i < V; ++i) {
                std::cout << "Vertex " << i << ": ";
                for (const auto& succ : list[i]) {
                    std::cout << "(" << succ.successor << ", " << succ.weight << ") ";
                }
                std::cout << std::endl;
            }
        }


        };

        // Additional methods to manipulate the adjacency list can be added here