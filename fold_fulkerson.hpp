#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <algorithm>

struct FoldFulkerson
{

    int Nbsommet;
    float **matrix;
    bool *Marque;
    float max_flow; 

    FoldFulkerson()
    {
        Nbsommet = 0;
        matrix = nullptr;
        Marque = nullptr;
        max_flow = 0.0;
    }

    void parse_file(std::string filename)
    {
        std::ifstream file(filename);
        if (!file)
        {
            std::cerr << "Error opening file: " << filename << std::endl;
            return;
        }
        else
        {
            int u, v = 0;
            float w = 0.0;
            file >> Nbsommet;
            matrix = new float *[Nbsommet];
            for (int i = 0; i < Nbsommet; ++i)
            {
                matrix[i] = new float[Nbsommet];
            }
            Marque = new bool[Nbsommet];
            for (int i = 0; i < Nbsommet; ++i)
            {
                Marque[i] = false;
            }
            while (file >> u >> v >> w)
            {
                matrix[u][v] = w;
            }
            std::cout << "Matrix loaded from file:" << std::endl;
            file.close();
        }
    }

    void display_graph()
    {

        for (int i = 0; i < Nbsommet; i++)
        {
            for (int j = 0; j < Nbsommet; j++)
            {

                std::cout << matrix[i][j] << " ";
            }

            std::cout << std::endl;
        }
    }


    bool Dfs(bool *visited, int *parent, int node, int sink){
        visited[node] = true;
        if (node == sink)
            return true;
        for (int v = 0; v < Nbsommet; v++){
            float w = matrix[node][v];
            if (!visited[v] && w > 0){
                parent[v] = node;
                if (Dfs(visited, parent, v, sink)){
                    return true;
                }
            }
        }
        return false;
    }
    

    void Fold_Fulkerson()
    {
        int parent[Nbsommet];
        bool visited[Nbsommet];
        max_flow = 0.0;
        bool stop = false;
        while(stop < true){
            for (int i = 0; i < Nbsommet; i++){
                visited[i] = false;
                parent[i] = -1;
            }
            if (!Dfs(visited, parent, 0, Nbsommet - 1)){
                stop = true;
                break;
            }
            float path_flow = INFINITY;
            for (int v = Nbsommet - 1; v != 0; v = parent[v]){
                int u = parent[v];
                path_flow = std::min(path_flow, matrix[u][v]);
            }
            for (int v = Nbsommet - 1; v != 0; v = parent[v]){
                int u = parent[v];
                matrix[u][v] -= path_flow;
                matrix[v][u] += path_flow;
            }
            max_flow += path_flow;


        }
    }

    void display_result(){
        std::cout << "The maximum possible flow is: " << max_flow << std::endl;
        std::cout << "The residual graph is: " << std::endl;
        display_graph();
    }

    ~FoldFulkerson()
    {
        for (int i = 0; i < Nbsommet; ++i)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
        delete[] Marque;
    }

};
