#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <tr1/utility> //tr1
#include <vector> 

using namespace std;
using namespace std::tr1;

struct positions {
  double xPos,
         yPos;
};

typedef vector<int> vectorInts;
typedef vector<positions> vectorPositions;
vectorPositions vectorInputPositions;

struct individual {
  vector<int> sequenceOfPointers;
  double cost;
};

typedef vector<individual> vectorIndividual;
vectorIndividual allIndividuals; 
vectorIndividual newIndividuals; 

struct sortByDistance {
  bool operator()(const individual unsortedIndividual1,  const individual unsortedIndividual2) const{
    return (unsortedIndividual1.cost < unsortedIndividual2.cost);
  }
};

double calculateCost(double x1, double x2, double y1, double y2) {
  return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

void population (vectorInts& x) {
  random_shuffle(x.begin(), x.end());
}

void fitness (vectorInts& randomizedVector, int individualSize) {
  double totalDistance = 0;

  for (int i = 0; i < individualSize; i++) {
    if (i == 0) {
      totalDistance += calculateCost(vectorInputPositions[randomizedVector[i]].xPos, 
                                     vectorInputPositions[randomizedVector[i]].yPos, 
                                     vectorInputPositions[randomizedVector[individualSize - 1]].xPos, 
                                     vectorInputPositions[randomizedVector[individualSize - 1]].yPos);
    }
    else {
      totalDistance += calculateCost(vectorInputPositions[randomizedVector[i]].xPos, 
                                     vectorInputPositions[randomizedVector[i]].yPos, 
                                     vectorInputPositions[randomizedVector[i - 1]].xPos, 
                                     vectorInputPositions[randomizedVector[i - 1]].yPos);
    } 
  }

  individual individualWithDates = {randomizedVector, totalDistance};
  allIndividuals.push_back(individualWithDates);
  sort(allIndividuals.begin(), allIndividuals.end(), sortByDistance());
}

void selection (vectorIndividual& allIndividuals) { //Select individuals of population
  individual parent1 = {allIndividuals[0].sequenceOfPointers, allIndividuals[0].cost};
  individual parent2 = {allIndividuals[1].sequenceOfPointers, allIndividuals[1].cost};

  newIndividuals.push_back(parent1);
  newIndividuals.push_back(parent2);
}

void mutation (vectorInts& child) {
  int swap1, 
      swap2,
      sizeOfVector = child.size();

  swap1 = rand() % sizeOfVector;
  swap2 = rand() % sizeOfVector;

  swap(child[swap1], child[swap2]);
}

void crossOver () {
  int decision,
      sizeOfVector = newIndividuals[0].sequenceOfPointers.size();

  individual child;
  vectorInts newVectorChild, verifyRepetition(sizeOfVector, 0);

  for (int i = 0; i < sizeOfVector; i++) {
    decision = rand() % 2;

    if (decision == 0) 
      newVectorChild.push_back(newIndividuals[0].sequenceOfPointers[i]);
    else
      newVectorChild.push_back(newIndividuals[1].sequenceOfPointers[i]);
  }
  
  for (int i = 0; i < sizeOfVector; i++) {
    if (verifyRepetition[newVectorChild[i] - 1] == 0)
      verifyRepetition[newVectorChild[i]]++;
    else {
      newVectorChild[i] = -1;
    }
  }

  for (int i = 0; i < sizeOfVector; i++) {
    if (newVectorChild[i] == -1) {
      for (int j = 0; j < sizeOfVector; j++) {
        if (verifyRepetition[j] == 0) {
          newVectorChild[i] = j + 1;
        }
      }
    }
  }

  int mutationTax = rand() % 100;

  if (mutationTax < 1)
    mutation(newVectorChild);

  newIndividuals.push_back({newVectorChild, 0});
}


/*--------------------------------------------MAIN---------------------------------------------------*/
int main () {
  int numVertex,
      numIndividual = 25,
      generations = 100000,
      aux;

  double xPosition,
         yPosition;

  positions inputPosition; 
  vectorInts randomVectorInts;

  srand(time(NULL));

  cin >> numVertex;
  for (int i = 0; i < numVertex; i++) {
    cin >> aux;
    cin >> xPosition >> yPosition;

    inputPosition = {xPosition, yPosition};
    vectorInputPositions.push_back(inputPosition);
    randomVectorInts.push_back(i + 1);
  }

  for (int i = 0; i < numIndividual; i++) {
    population(randomVectorInts);
    fitness(randomVectorInts, numVertex);
  }
  
  for (int i = 0; i < generations; i++) {
    selection(allIndividuals);
    
    int probability = rand() % 10;

    if (probability <= 8) //ocorre crossover com 80 %
      crossOver();
      
    int sizeOfIndividualVector = newIndividuals[0].sequenceOfPointers.size();
    for (int j = 0; j < newIndividuals.size(); j++) 
      fitness(newIndividuals[j].sequenceOfPointers, sizeOfIndividualVector);

    int difference = allIndividuals.size() - newIndividuals.size();

    for (int j = 0; j < difference; j++)
      allIndividuals.pop_back();

    newIndividuals.clear();
  }   

  cout << allIndividuals[0].cost << endl;
}
