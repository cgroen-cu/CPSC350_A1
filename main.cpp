//main file, where main method lives

#include "a1.h"


int main(int argc, char** argv){
  //Int and while loop to check if another file is to be calculated
  //Starts at 1
  bool play = 1;
  //Default is no to prevent loop
  string entry = "n";
  //File name for reentry
  string filename = "test.txt";

  //Open file to write to
  ofstream output;
  output.open("Groen.out");
  // First time running, print student info
  output << "Name: Christian Groen \nStudent ID: 2324823 \n\n";


  //While Loop checking files and processing DNA
  while(play == 1 || play == 2){
    cout << "Type your file including its extension: ";
    cin >> filename;

    processDNA *p1 = new processDNA(filename);

    p1->inputDNA(p1->getFile());



    output << "Calculations from file; " << filename << endl;
    //Main Calculations
    output << "Sum: " << (p1->printSum()) << endl;
    output << "Mean: " << (p1->printMean()) << endl;
    output << "Variation: " << (p1->printVariance()) << endl;

    //Nucleotide probability



    //Bigram outputs
    output << (p1->printbigramA()) << endl;
    output << (p1->printbigramT()) << endl;
    output << (p1->printbigramC()) << endl;
    output << (p1->printbigramG()) << endl;


    // output << "Count A: " << (p1->getCountA()) << endl;
    // output << "Count T: " << (p1->getCountT()) << endl;
    // output << "Count C: " << (p1->getCountC()) << endl;
    // output << "Count G: " << (p1->getCountG()) << endl;

    output << (p1->print1000()) << endl;


    delete p1;

    cout << "Do you want to input another file? (Y/N): ";
    cin >> entry;
    if (entry == "y"){
      play = 2;
    } else {
      //Close file
      output.close();
      play = 0;
    }
  }



}
