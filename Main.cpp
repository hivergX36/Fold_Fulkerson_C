#include <iostream>
#include "fold_fulkerson.hpp"


int main() {
  FoldFulkerson foldfulkerson = FoldFulkerson();
  foldfulkerson.parse_file("data_2.txt");
  foldfulkerson.Fold_Fulkerson();
  foldfulkerson.display_result();

  return 0;
}

 