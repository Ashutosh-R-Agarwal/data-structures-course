#include <iostream>
#include <vector>
#include<stdlib.h>
#include <stdio.h>
#include <string.h>

using std::vector;
using std::pair;




int reach(vector<vector<int> > &adj, int x, int y, int *visited) {

  visited[x] = 1;


//  for(vector <int>::iterator it = adj[x]->begin(); it != adj[x].end(); it++)
  for(size_t i = 0; i < adj[x].size(); i++)
  {
      if (!visited[adj[x][i]])
      {
          if (adj[x][i] == y)
            return 1;

          if(reach(adj, adj[x][i], y, visited))
            return 1;
      }

  }


  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  int array[n];
  memset(array, 0 , sizeof(array));


  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1, array);
}
