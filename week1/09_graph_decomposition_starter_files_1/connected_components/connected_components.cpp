#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>

using std::vector;
using std::pair;

int visited[10000];

int reach(vector<vector<int> > &adj, int x) {

    visited[adj[x][0]] = 1;
    for(size_t i = 0; i < adj[x].size(); i++)
    {
            if (!visited[adj[x][i]])
            {
                reach(adj, adj[x][i]);
            }
    }
    return 1;
}


int number_of_components(vector<vector<int> > &adj) {
  //int res = 0;
  int cc = 0;

  for (size_t j = 0; j < adj.size(); j++)
  {
        if (!(visited[adj[j][0]]))
        {

             reach(adj, adj[j][0]);
             cc++;
        }

    }



  return cc;
}

int main() {
  size_t n, m;
  //std::cin >> n >> m;
  //int array[n];

  n = 4;
  m = 2;
  int temp[] = { 1 , 2 , 3 , 2 };
  memset(visited, 0, sizeof(visited));
  vector<vector<int> > adj(n, vector<int>());

  for (size_t i = 0; i < m; i++) {
    int x, y;
 //   std::cin >> x >> y;
    adj[temp[i]].push_back(temp[i+1]);
    adj[temp[i+1]].push_back(temp[i]);
  }
  std::cout << number_of_components(adj);
}
