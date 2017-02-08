#include <iostream>
#include <cmath>
#include <vector>
#include <valarray>

using namespace std;
//using namespace std::tr1;

struct city {
  double xPos,
         yPos;
};

typedef vector<city> tour;
//typedef valarray<node> tour;

double calculateCities (double x1, double x2, double y1, double y2) {
    return sqrt(sqrt(abs(x2 - x1)) + sqrt(abs(y2 - y1)));
}

double fitness () { //calculateTour
  for (iterator it = )  
}

double selection () {
 
}

double crossOver () {

}

double mutation () {

}

double accepting () {

}

double replace () {

}

double test () {

}


int main () {
  int numVertex,
      generations = 10000;
      aux;

  double xPosition,
         yPosition;

  cin >> numVertex;
  for (int i = 0; i < numVertex; i++) {
    cin >> aux;
    cin.ignore();
    cin >> xPosition >> yPosition;

    city = {xPosition, yPosition};
    tour.push_back(city);
  }

  for (int i = 0; i < generations; i++) {
    fitness();
    //Create new population
    selection();
    crossOver();
    mutation();
    accepting();
    replace();
    test();
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
