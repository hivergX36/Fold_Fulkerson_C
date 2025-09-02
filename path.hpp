#include <iostream>

class Path {

    public:

    int *path;
    int *cost;
    int size_of_path;

    Path(int& size){
        path = new int[size];
        cost = new int[size];
        size_of_path = size;
        for (int i = 0; i < size; i++) {
            path[i] = -1; // Initialize path with -1 which is null value 
            cost[i] = 2147483647; // Initialize cost with maximum integer value
        }
    }

    ~Path() {
        delete[] path;
        delete[] cost;
    }

    void display_path() {
        for (int i = 0; i < size_of_path; i++) {
            std::cout << "Vertex: " << i << ", Path: " << path[i] << ", Cost: " << cost[i] << std::endl;
        }
    }              

};