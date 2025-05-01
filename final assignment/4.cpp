#include<bits/stdc++.h> // include all header files
using namespace std;

// function to input edges into an adjacency matrix representation
void inputMatrix(int n, int e, int graph[101][101]) {
  for (int i = 0; i < e; i++) { // run a loop to input e edges
    int u, v; // declare variables u and v to store edge endpoints
    cin >> u >> v; // input the source node u and destination node v
    graph[u][v] = graph[v][u] = 1; // set graph[u][v] and graph[v][u] to 1 for an undirected edge
  }
}

// function to input edges into an adjacency list representation
void inputList(int n, int e, vector<int> graphList[]) {
  for (int i = 0; i < e; i++) { // run a loop to input e edges
    int u, v; // declare variables u and v to store edge endpoints
    cin >> u >> v; // input the source node u and destination node v
    graphList[u].push_back(v); // add v to the adjacency list of u
    graphList[v].push_back(u); // add u to the adjacency list of v for an undirected edge
  }
}

// main function to input and display a graph as a matrix or list based on user choice
int main() {
  int n, e; // declare variables n (number of vertices) and e (number of edges)
  cout << "Enter number of vertices and edges: "; // prompt user for number of vertices and edges
  cin >> n >> e; // input the number of vertices n and edges e

  int graph[101][101] = { 0 }; // initialize 2D array for adjacency matrix, size 101x101, all set to 0
  vector<int> graphList[10]; // initialize array of vectors for adjacency list, max 10 nodes

  cout << "Choose input type (1 for Matrix, 2 for List): "; // prompt user to choose representation type
  int choice; // declare variable choice to store user’s selection
  cin >> choice; // input the user’s choice

  if (choice == 1) { // if user chooses 1 for adjacency matrix
    inputMatrix(n, e, graph); // call inputMatrix to populate the adjacency matrix
    cout << "Adjacency Matrix:\n"; // output label for adjacency matrix
    for (int i = 1; i <= n; i++) { // run a loop over rows from 1 to n
      for (int j = 1; j <= n; j++) // run a nested loop over columns from 1 to n
        cout << graph[i][j] << " "; // output each element of the matrix followed by a space
      cout << endl; // output a newline after each row
    }
  }
  else if (choice == 2) { // if user chooses 2 for adjacency list
    inputList(n, e, graphList); // call inputList to populate the adjacency list
    cout << "Adjacency List:\n"; // output label for adjacency list
    for (int i = 1; i <= n; i++) { // run a loop over nodes from 1 to n
      cout << i << "-> "; // output the current node followed by an arrow
      for (int v : graphList[i]) // run a loop through all neighbors of node i
        cout << v << " "; // output each neighbor followed by a space
      cout << endl; // output a newline after each node’s neighbors
    }
  }
  else { // if user enters an invalid choice
    cout << "Invalid choice\n"; // output an error message
  }

  return 0; // exit the program
}