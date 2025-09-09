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

    FoldFulkerson()
    {
        Nbsommet = 0;
        matrix = nullptr;
        Marque = nullptr;
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


    void Dfs(bool &visited, int &parent, int node, int sink){
        visited[node] = True
        if node == sink:
            return True
        for v in range(self.NbVertices):
            w = self.adjacency_Matrix[node][v]
            if visited[v] == False and w > 0:
                parent[v] = s
                if self.Dfs(visited, parent, v, sink):
                    return True
        return False
    }
    

    void Fold_Fulkerson()
    {
        int pred[Nbsommet];
        bool visited[Nbsommet];
        int succ;
        int pds_succ;
        int dist = 0;
        int Nodes[Nbsommet];
        int chemin[Nbsommet];
        int distance[Nbsommet];
        int lenght;

        file.push(0);

        for (int i = 0; i < Nbsommet; i++)
        {
            Nodes[i] = i;
            distance[i] = 100000;
            chemin[i] = 0;
        }

        distance[0] = 0;
        file.push(0);
        lenght = file.size();

        while (lenght > 0)
        {
            prec = file.front();
            std::cout << "Le predecesseur est: " << prec << " " << std::endl;
            file.pop();
            for (int i = 0; i < Nbsommet; i++)
            {
                if (Matrice[prec][i] > 0)
                {
                    succ = i;
                    pds_succ = Matrice[prec][i];
                    std::cout << "le successeur est: " << succ << std::endl;
                    std::cout << "le poids du sucesseur est: " << pds_succ << std::endl;
                    dist = distance[prec] + succ;
                    std::cout << "la distance du calcul est: " << dist << std::endl;
                    if (dist < distance[succ])
                    {

                        distance[succ] = dist;
                        chemin[succ] = prec;
                        file.push(i);
                    }
                }
                lenght = file.size();
                std::cout << "La longueur de la pile est: " << lenght << std::endl;
            };
            for (int i = 0; i < Nbsommet; i++)
            {

                std::cout << chemin[i] << " ";
            };
            std::cout << std::endl;
        };
    };
};
