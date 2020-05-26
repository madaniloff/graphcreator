//This program creates graphs and can search for the shortest path
//Date: 5/27/2020
//Author: Mark Daniloff

#include <iostream>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>

using namespace std;

//Struct for vertex
struct Vertex {
  char name;
  int index;
  int edge[21];
};

//Function initializations
void addVertex(Vertex **grid, int ix);
void removeVertex(Vertex **grid, int ix);
void addEdge(Vertex** grid, int ix);
void removeEdge(Vertex** grid, int ix);
void Print(Vertex **grid, int ix);
void Path(Vertex **grid, int ix);
Vertex* findVertex(Vertex **grid, char in, int ix);

int main() {
  //Initialize variables
  bool running = true;
  Vertex **grid = new Vertex*[21];
  //Index number
  int ix = 0;
  int input;
  while (running != false) {
    cout << "Enter..." << endl;
    cout << "1 to add a vertex" << endl;
    cout << "2 to remove a vertex" << endl;
    cout << "3 to add an edge" << endl;
    cout << "4 to remove an edge" << endl;
    cout << "5 to print" << endl;
    cout << "6 to find the shortest path" << endl;
    cout << "7 to quit" << endl;
    cin >> input;
    cin.ignore();
    //Add vertex
    if (input == 1) {
      addVertex(grid, ix);
      ix++;
    }
    //Remove vertex
    else if (input == 2) {
      removeVertex(grid, ix);
      ix--;
    }
    //Add edge
    else if (input == 3) {
      if (grid[0] == NULL || grid[1] == NULL) {
	cout << "There are not enough vertices to create an edge!" << endl;
      }
      else {
	addEdge(grid, ix);
      }
    }
    //Remove edge
    else if (input == 4) {
      if (grid[0] == NULL || grid[1] == NULL) {
	cout << "There are not enough vertices to remove an edge!" << endl;
      }
      else {
	removeEdge(grid, ix);
      }
    }
    //Print
    else if (input == 5) {
      Print(grid, ix);
    }
    //Shortest path
    else if (input == 6) {
      Path(grid, ix);
    }
    //Quit
    else if (input == 7) {
      running = false;
    }
  }
}

//Add vertex
void addVertex(Vertex **grid, int ix) {
  //Prompt user for name
  char input;
  cout << "Enter a label for the vertex:" << endl;
  cin >> input;
  cin.ignore();
  //Create vector object
  Vertex* v = new Vertex();
  v->name = input;
  v->index = ix;
  grid[ix] = v;
}

//Remove vertex
void removeVertex(Vertex **grid, int ix) {
  //Prompt user for label to remove
  char input;
  cout << "Enter a label to remove" << endl;
  cin >> input;
  cin.ignore();
  //Locate the vertex to be removed
  Vertex* v = findVertex(grid, input, ix);
  //If vertex doesn't exist
  if (v == NULL) {
    cout << "This vertex does not exist!" << endl;
  }
  //If it does exist
  else {
    int i = v->index;
    //Delete the vertex and its data
    delete v;
    v = NULL;
    //Move elements in the grid down by 1
    while (i < ix) {
      //If deleted vertex was the last one
      if (i == ix-1) {
	grid[i] = NULL;
	break;
      }
      else {
	grid[i] = grid[i+1];
	grid[i]->index = i;
	i++;
      }
    }
  }
}

//Add edge
void addEdge(Vertex **grid, int ix) {
  char in1, in2;
  int weight;
  cout << "Enter first vertex" << endl;
  cin >> in1;
  cin.ignore();
  cout << "Enter second vertex" << endl;
  cin >> in2;
  cin.ignore();
  //Return the vertices with the appropriate labels
  Vertex* v1 = findVertex(grid, in1, ix);
  Vertex* v2 = findVertex(grid, in2, ix);
  if (v1 == NULL || v2 == NULL) {
    cout << "Invalid vertices!" << endl;
  }
  else {
    //Ask user for weight
    cout << "Enter edge weight" << endl;
    cin >> weight;
    cin.ignore();
    //Set edge between the vertices
    v1->edge[v2->index] = weight;
    v2->edge[v1->index] = weight;    
  }
}

//Remove edge
void removeEdge(Vertex **grid, int ix) {
  char in1, in2;
  cout << "Enter first vertex" << endl;
  cin >> in1;
  cin.ignore();
  cout << "Enter second vertex" << endl;
  cin >> in2;
  cin.ignore();
  //Return the vertices with the appropriate labels
  Vertex* v1 = findVertex(grid, in1, ix);
  Vertex* v2 = findVertex(grid, in2, ix);
  if (v1 == NULL || v2 == NULL) {
    cout << "Invalid vertices!" << endl;
  }
  else {
    //Delete the edge
    v1->edge[v2->index] = 0;
    v2->edge[v1->index] = 0;
    
  }
}

//Return the vertex with the inputted label
Vertex* findVertex(Vertex **grid, char input, int ix) {
  int i = 0;
  while (i < ix) {
    if (grid[i]->name == input) {
      return grid[i];
    }
    else {
      i++;
    }
  }
  return NULL;
}

//Print out adjacency table
void Print(Vertex **grid, int ix) {
  //Create empty display array
  //[col][row]
  char display[22][22]; 
  for (int i = 0; i < 22; i++) {
    for (int j = 0; j < 22; j++) {
      display[i][j] = 0;
    }
  }
  //Keep track of grid index
  int g = 0;
  //Create edge column with vertex names
  for (int i = 1; i < ix+1; i++) {
    display[i][0] = grid[g]->name;
    g++;
      }
  g = 0;
  //Create edge row with vertex names
  for (int i = 1; i < ix+1; i++) {
    display[0][i] = grid[g]->name;
    g++;
  }
  //Fill in the rest of the adjacency table
  for (int i = 1; i < ix+1; i++) {
    Vertex* a = grid[i-1];
    for (int j = 1; j < ix+1; j++) {
      Vertex* b = grid[j-1];
      //If an edge exists
      if (a->edge[b->index] != 0) {
	display[i][j] = 'T';
      }
      else {
	display[i][j] = 'F';
      }
    }
  }
  //Print the adjacency matrix
  for (int i = 0; i < ix+1; i++) {
    for (int j = 0; j < ix+1; j++) {
      cout << display[i][j] << " ";
    }
    cout << endl;
  }
}

//Find the shortest path using Dijkstra's Algorithm
void Path(Vertex **grid, int ix) {
  
}
