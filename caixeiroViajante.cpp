#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <valarray>

using namespace std;
//using namespace std::tr1;



struct city {
  double xPos,
         yPos;
};

typedef vector<city> vectorCities;

struct tour {
  vectorCities visitedCities;
  double distance;
};

typedef vector<tour> vectorTour;
vectorTour ableTours; 

//verify sort condition
struct sortByDistance {
  bool operator()(const vectorTour& unsortedPopulation1,  const vectorTour& unsortedPopulation2) const{
    return (unsortedPopulation1.distance > unsortedPopulation2.distance);
  }
};

/*
bool sortByDistance (const vectorTour& unsortedTour1, const vectorTour& unsortedTour2) const {
  for (size_t i = 0; i < unsortedTour1.size() && i < unsortedTour2.size(); i++) {
    if (unsortedTour1[i] > unsortedTour2)
  }
}
*/

double calculateTour(double x1, double x2, double y1, double y2) {
  return sqrt(sqrt(abs(x2 - x1)) + sqrt(abs(y2 - y1)));
}

void fitness (vectorTour& ableTours, vectorCities& selectedTour, int tourSize) { //calculateTour
  double totalDistance = 0;

  for (int i = 1; i < tourSize; i++) {
    if (i == tourSize - 1) {
      huotalDistance += calculateTour(selectedTour[0].xPos, selectedTour[0].yPos, 
                                     selectedTour[i].xPos, selectedTour[i].yPos);
    }
    else {
      totalDistance += calculateTour(selectedTour[i].xPos, selectedTour[i].yPos, 
                                     selectedTour[i - 1].xPos, selectedTour[i - 1].yPos);
    } 
  }

  tour accomplishedJourney = {selectedTour, totalDistance};
  ableTours.push_back(accomplishedJourney);
}

double selection (vectorTour& population) { //Select tours of population
  sort(population.begin(), population.end(), sortByDistance());

  tour pai1 = {population[0].visitedCities, population[0].distance};
  tour pai2 = {population[1].visitedCities, population[1].distance};
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
      generations = 10000,
      aux;

  double xPosition,
         yPosition;

  city oneCity; 

  cin >> numVertex;
  for (int i = 0; i < numVertex; i++) {
    cin >> aux;
    cin.ignore();
    cin >> xPosition >> yPosition;

    oneCity = {xPosition, yPosition};
    vectorCities.push_back(city);
  }

  for (int i = 0; i < generations; i++) {
    fitness(vectorCities, vectorCities.size());
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
