#include "path.hpp"
#include <vector>
#include <fstream>
#include <algorithm>
#include <queue> 
#include "Adjacency_list.hpp"

class fold_fulkerson
{

    private:
    int V; // Number of vertics
    Adgency_list* adj_list; // Adjacency list representation of the graph
    Path *result_path; // Resulting path after running Prim's algorithm
    bool is_negative_cycle = false; // Flag to indicate if a negative cycle exists
    bool *visited;

    public:

    fold_fulkerson(int v) : V(v) {
        adj_list = new Adgency_list(V);
        result_path = new Path(V);
    }

    ~fold_fulkerson() {
        delete adj_list;
        delete result_path;
    }

    void add_edge_components(int u, int v, int weight) {
        adj_list->add_edge(u, v, weight);
    }

    void parse_data(std::string filename){
     std::ifstream file(filename);
        if (!file) {
            std::cerr << "Error opening file: " << filename << std::endl;
            return;
        }else{
            int V,u, v, weight;
            file >> V;
            adj_list = new Adgency_list(V);
            result_path = new Path(V);
            visited = new bool[V];
            for (int i = 0; i < V; ++i) {
                visited[i] = false; // Initialize visited array
            }
            while (file >> u >> v >> weight) {
                add_edge_components(u, v, weight);
            }
            std::cout << "Data parsed successfully from " << filename << std::endl;
            file.close();
        }
    };

    void display_adjacency_list() {
        adj_list->display_adjacency_list();
    }


    void negative_cycle_detection() {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                int current_vertex = j; 
                visited[current_vertex] = true; // Mark the current vertex as visited
                // Process the current vertex and its edges
                for (const auto& succ : adj_list->list[current_vertex]) {
                    int successor = succ.successor;
                    int weight = succ.weight;

                    // Check if this edge can be added to the result path
                    if (result_path->cost[successor] > weight + result_path->cost[current_vertex]) {
                        if (visited[successor] == false){
                            visited[successor] = true; // Mark the successor as visited
                        } else {
                            is_negative_cycle = true;
                            std::cout << "Negative cycle detected involving vertex: " << successor << std::endl;
                        }
                 
                    }
                }
            }
        }
    }

    void display_negative_cycle() {
        if (is_negative_cycle) {
            std::cout << "Negative cycle exists in the graph." << std::endl;
        } else {
            std::cout << "No negative cycle detected in the graph." << std::endl;
        }
        for (int i = 0; i < V; ++i) {
            std::cout << visited[i] << " ";
         
        }
    }



    void run_BellmanFord() {
      for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            int current_vertex = j; 
            // Process the current vertex and its edges
            for (const auto& succ : adj_list->list[current_vertex]) {
                int successor = succ.successor;
                int weight = succ.weight;

                // Check if this edge can be added to the result path
                if (result_path->cost[successor] > weight + result_path->cost[current_vertex]) {
                    result_path->cost[successor] = weight + result_path->cost[current_vertex];
                    result_path->path[successor] = current_vertex;
                }
            }
        }
        // Implementation of Prim's algorithm
    }
}

    void display_result_path() {
        result_path->display_path();
    }
};