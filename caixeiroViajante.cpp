#include <iostream>
#include <vector>
#include <valarray>

using namespace std;
//using namespace std::tr1;

struct node {
  double xPos,
        yPos;
};

//typedef vector<double> tour;
typedef valarray<node> tour;


double calculateCities () {
  
}

int calculateTour () {
  
}

int selection () {
 
}

int crossOver () {

}

int mutation () {

}

int accepting () {

}

int replace () {

}

int test () {

}


int main () {
  int numVertex;
  int xPosition,
      yPosition;

  cin >> numVertex;

  for (int i = 0; i < numVertex; i++) {
    cin >> xPosition >> yPosition;
    
  }
  


  /* Passos
   * Fitness == Adequacao (re-calculate the values between cities)
   * New population (criate a new trajectory, from the following steps)
   *    Selection (select two cities to turn into the parents)
   *    Crossover ()
   *    Mutation
   *    Accepting
   * Replace
   * Test (if the population returns the best condition or the result, stop the algorithm and return the value)
   * Loop (loop the process from Fitness)
   *
   * Codigo por permutacao
   *
   */
}
