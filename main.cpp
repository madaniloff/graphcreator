//This program creates graphs and can search for the shortest path
//Date: 5/27/2020
//Author: Mark Daniloff

#include <iostream>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

//Struct for vertex
struct Vertex {
  char name;
  int index;
  int edges[21];
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
      //removeVertex(grid, ix);
      ix--;
    }
    //Add edge
    else if (input == 3) {
      
    }
    //Remove edge
    else if (input == 4) {

    }
    //Print
    else if (input == 5) {

    }
    //Shortest path
    else if (input == 6) {

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
  cin >> char;
  cin.ignore();
  
  
}
