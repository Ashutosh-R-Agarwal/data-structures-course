#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>

using std::vector;
using std::pair;
using std::cout;

int visited[10000];

void reach(vector<vector<int> > &adj, int x) {

    visited[x] = 1;
    for(size_t i = 0; i < adj[x].size(); i++)
    {
            if (!visited[adj[x][i]])
            {
                reach(adj, adj[x][i]);
            }
    }
}


int number_of_components(vector<vector<int> > &adj, int n) {
  //int res = 0;
  int cc = 0;
//adj.size()
  for (size_t j = 1; j <= n ; j++)
  {
        if (adj[j].size() && !(visited[j]))
        {

             reach(adj, j);
             cc++;
        }
        if (!adj[j].size())
            cc++;

        /*cout <<  "\n IMP " << j << " " << adj[j].size() <<"\n";

         for(size_t i = 0; i < adj[j].size(); i++)
         {
             cout << adj[j][i] << " ";
         } */

    }

  return cc;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  //int array[n];
//  n = 4;
 // m = 2;
 // int temp[] = { 1 , 2 , 3 , 2 };
  memset(visited, 0, sizeof(visited));
  vector<vector<int> > adj(n+2, vector<int>());

  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[y].push_back(x);
    adj[x].push_back(y);
  }
//  printf("\nCLOSING");
  std::cout << number_of_components(adj, n);
}
