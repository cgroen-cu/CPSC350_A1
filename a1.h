#include <iostream>  //pre-processor directive
#include <cstdlib>   //Randomfunction
#include <fstream>    //file IO
#include <math.h>     //Square root
#include <ctime>
#include <random>

using namespace std;

//header file, .h extension
class processDNA{
  public:
    //constructor
    processDNA(string inputFile);
    //destructor
    ~processDNA();
    void inputDNA(string file);

    //int randomNum;

    string file;
    string line;

    double nSum;
    double sumSquares;
    double mean;
    double stdDev;

    int count;
    int countLines;

    //single nucleotides
    int countA;
    int countT;
    int countC;
    int countG;

    //Single Probabilities
    double probA;
    double probT;
    double probC;
    double probG;

    //Double nucleotides
    int countAA;
    int countAC;
    int countAT;
    int countAG;
    int countCA;
    int countCT;
    int countCC;
    int countCG;
    int countTA;
    int countTT;
    int countTC;
    int countTG;
    int countGA;
    int countGT;
    int countGC;
    int countGG;

//MODIFIERS
    void setFile();

    void incCount();
    void incA();
    void incT();
    void incC();
    void incG();

//ACCESSORS
    string getFile();

    int getCount();
    int getCountA();
    int getCountT();
    int getCountC();
    int getCountG();

//These accessors also do calcuation so we can print
// out the probability for each bigram to their First
// letter. Prints out as 1 string.
    string printbigramA();
    string printbigramT();
    string printbigramC();
    string printbigramG();

  //This does sum
    string printSum();

  //This does mean
    string printMean();

  //this does variance AND Standard Deviation
    string printVariance();

  //generate nucleotides according to input frequency
    string generateNuc();
  //Printing out the gaussian curve
    string print1000();


  private:
    // none
};
