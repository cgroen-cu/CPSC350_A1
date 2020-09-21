#include "a1.h"


//default constructor
processDNA::processDNA(string inputFile){
  file = inputFile;
  line;

  //randomNum = 0;

  nSum = 0;
  sumSquares = 0;
  mean = 0;
  stdDev = 0;

  count = 0;
  countLines = 0;
  countA = 0;
  countT = 0;
  countC = 0;
  countG = 0;

  probA = 0;
  probT = 0;
  probC = 0;
  probG = 0;

  countAA = 0;
  countAT = 0;
  countAC = 0;
  countAG = 0;
  countTA = 0;
  countTT = 0;
  countTC = 0;
  countTG = 0;
  countCA = 0;
  countCT = 0;
  countCC = 0;
  countCG = 0;
  countGA = 0;
  countGT = 0;
  countGC = 0;
  countGG = 0;

}

//destructor
processDNA::~processDNA(){
}

//TAkes in a counts/processes each line of nucleotides in the file
void processDNA::inputDNA(string file){
  //Open File
  ifstream myfile;
  myfile.open (file);
  //Debug info
  //cout << "Opened File \n";

  //Iterate through File
  while (getline (myfile,line)){

    //Debbug info
    //cout << "next line: " << line << "\n";

    //iterate through each line
    //Iterates 2 at a time, to get the bigrams
    for (int i = 0; i < line.size()-1; i+=2){
      //Debug info
      //cout << i << line[i] << "\n";

      //Check to see if current character is equal to A
      if(toupper(line[i]) == 'A'){
        incA();
        //Debug info
        //cout << "Adding A \n";
        if(toupper(line[i+1]) == 'A'){
          //Increment the second nucleotide
          incA();
          //Debug info
        //  cout << "Adding 2nd A \n";
          //Icrement to the bigram
          ++countAA;

        } else if (toupper(line[i+1]) == 'T'){   //If not A, checking for T
          incT();
          ++countAT;
        //  cout << "Adding 2nd T \n";

        } else if (toupper(line[i+1]) == 'G'){   // If not T, checking for G
          incG();
        //  cout << "Adding 2nd G \n";
          ++countAG;

        } else if (toupper(line[i+1]) == 'C'){   // if not G, checking for C
          incC();
        //  cout << "Adding 2nd C \n";
          ++countAC;

        } else{
        //  cout << "ERROR: " << line[i+1] << " not a DNA nucleotide" << "\n";
        }

      //If first letter is T
      } else if (toupper(line[i]) == 'T'){   //If not A, checking for T
        incT();
      //  cout << "Adding T \n";
        if(toupper(line[i+1]) == 'A'){
          //Increment the second nucleotide
          incA();
          //Debug info
        //  cout << "Adding A \n";
          //Icrement to the bigram
          ++countTA;

        } else if (toupper(line[i+1]) == 'T'){   //If not A, checking for T
          incT();
          ++countTT;
      //    cout << "Adding T \n";

        } else if (toupper(line[i+1]) == 'G'){   // If not T, checking for G
          incG();
      //    cout << "Adding G \n";
          ++countTG;

        } else if (toupper(line[i+1]) == 'C'){   // if not G, checking for C
          incC();
      //    cout << "Adding C \n";
          ++countTC;

        } else{
      //    cout << "ERROR: " << line[i+1] << " not a DNA nucleotide" << "\n";
        }

      //If first letter is G
      } else if (toupper(line[i]) == 'G'){   // If not T, checking for G
        incG();
    //    cout << "Adding G \n";
        if(toupper(line[i+1]) == 'A'){
          //Increment the second nucleotide
          incA();
          //Debug info
    //      cout << "Adding A \n";
          //Icrement to the bigram
          ++countGA;

        } else if (toupper(line[i+1]) == 'T'){   //If not A, checking for T
          incT();
          ++countGT;
      //    cout << "Adding T \n";

        } else if (toupper(line[i+1]) == 'G'){   // If not T, checking for G
          incG();
    //      cout << "Adding G \n";
          ++countGG;

        } else if (toupper(line[i+1]) == 'C'){   // if not G, checking for C
          incC();
    //      cout << "Adding C \n";
          ++countGC;

        } else{
    //      cout << "ERROR: " << line[i+1] << " not a DNA nucleotide" << "\n";
        }

      //If first letter is C
      } else if (toupper(line[i]) == 'C'){   // if not G, checking for C
        incC();
    //    cout << "Adding C \n";
        if(toupper(line[i+1]) == 'A'){
          //Increment the second nucleotide
          incA();
          //Debug info
    //      cout << "Adding A \n";
          //Icrement to the bigram
          ++countCA;

        } else if (toupper(line[i+1]) == 'T'){   //If not A, checking for T
          incT();
          ++countCT;
    //      cout << "Adding T \n";

        } else if (toupper(line[i+1]) == 'G'){   // If not T, checking for G
          incG();
    //      cout << "Adding G \n";
          ++countCG;

        } else if (toupper(line[i+1]) == 'C'){   // if not G, checking for C
          incC();
    //      cout << "Adding C \n";
          ++countCC;

        } else{
    //      cout << "ERROR: " << line[i+1] << " not a DNA nucleotide" << "\n";
        }

      } else{                               //If the character is not a nucleotide
      //  cout << "ERROR: " << line[i] << " not a DNA nucleotide" << "\n";
      }

    }
    //Calculate sum of squares for variation.
    sumSquares += (line.size()-1)*(line.size()-1);
    //DEBUG info
  //  cout << " Sum of Squares: " <<(line.size()-1)*(line.size()-1) << endl;

    //increment to the number of lines
    ++countLines;
  }

  //Close File
  myfile.close();
//  cout << "Closed File \n";

}

//MODIFIERS
void processDNA::incCount(){
  ++count;
}
void processDNA::incA() {
  ++countA;
}
void processDNA::incT() {
  ++countT;
}
void processDNA::incC() {
  ++countC;
}
void processDNA::incG() {
  ++countG;
}

//ACCESSORS
string processDNA::getFile(){
  return file;
}

int processDNA::getCount(){
  return count;
}
int processDNA::getCountA(){
  return countA;
}
int processDNA::getCountT(){
  return countT;
}
int processDNA::getCountC(){
  return countC;
}
int processDNA::getCountG(){
  return countG;
}

//Accessors that calculate and return calculations
//Nucleotide and Bigram probability
string processDNA::printbigramA(){
  //Nice explanatory output text
  string text = "There is a ";
  text+= to_string(probA);
  text+= " percent chance the nucleotide is A. Related bigram probability is as follows.\n";
  //Caclucates sum of the bigrams to use for probablity.
  //double p = countAA + countAT + countAC + countAG;
  double p = nSum/2;
  //Caclulates probability and adds it to the string
  text += " AA: " + to_string((countAA/p) * 100.0) + "% \n";
  text += " AT: " + to_string((countAT/p) * 100.0) + "% \n";
  text += " AC: " + to_string((countAC/p) * 100.0) + "% \n";
  text += " AG: " + to_string((countAG/p) * 100.0) + "% \n";
  //Outputs the string
  return text;
}
string processDNA::printbigramT(){
  //Nice explanatory output text
  string text = "There is a ";
  text+= to_string(probT);
  text+= " percent chance the nucleotide is T. If so, the bigram probability is as follows.\n";
  //Caclucates sum of the bigrams to use for probablity.
  double p = nSum/2;
  //Caclulates probability and adds it to the string
  text += " TA: " + to_string((countTA/p) * 100.0) + "% \n";
  text += " TT: " + to_string((countTT/p) * 100.0) + "% \n";
  text += " TC: " + to_string((countTC/p) * 100.0) + "% \n";
  text += " TG: " + to_string((countTG/p) * 100.0) + "% \n";
  //Outputs the string
  return text;
}
string processDNA::printbigramC(){
  //Nice explanatory output text
  string text = "There is a ";
  text+= to_string(probC);
  text+= " percent chance the nucleotide is C. If so, the bigram probability is as follows.\n";
  //Caclucates sum of the bigrams to use for probablity.
  double p = nSum/2;

  //Caclulates probability and adds it to the string
  text += " CA: " + to_string((countCA/p) * 100.0) + "% \n";
  text += " CT: " + to_string((countCT/p) * 100.0) + "% \n";
  text += " CC: " + to_string((countCC/p) * 100.0) + "% \n";
  text += " CG: " + to_string((countCG/p) * 100.0) + "% \n";
  //Outputs the string
  return text;
}
string processDNA::printbigramG(){
  //Nice explanatory output text
  string text = "There is a ";
  text+= to_string(probG);
  text+= " percent chance the nucleotide is G. If so, the bigram probability is as follows.\n";
  //Caclucates sum of the bigrams to use for probablity.
  double p = nSum/2;

  //Caclulates probability and adds it to the string
  text += " GA: " + to_string((countGA/p) * 100.0) + "% \n";
  text += " GT: " + to_string((countGT/p) * 100.0) + "% \n";
  text += " GC: " + to_string((countGC/p) * 100.0) + "% \n";
  text += " GG: " + to_string((countGG/p) * 100.0) + "% \n";
  //Outputs the string
  return text;
}

//print and calculate sum AND calculate nucleotide freuency
string processDNA::printSum(){
  nSum = countA + countT + countC +countG;

  //Also processes DNA
  probA = countA/nSum*100;
  probT = countT/nSum*100;
  probC = countC/nSum*100;
  probG = countG/nSum*100;

  return (to_string(nSum));

}

//calculate and prin mean
string processDNA::printMean(){
  mean = nSum/countLines;
  return (to_string(nSum/countLines));
}

//calculate and print variance AND standard Deviation
string processDNA::printVariance(){
  //String to return
  string text;
  double n2 = (nSum*nSum)/countLines;
    //DEBUG INFO
  //cout << n1 << endl;
  // cout << n2 << endl;
  double n1 = (sumSquares-n2)/(countLines);
    //DEBUG INFO
  // cout << sumSquares << endl;
  // cout << n1 << endl;
  // cout << countLines << endl;
  // cout << (sumSquares-n1) << "/" << (countLines-1) << endl;
  //Add the calculations to return string
  text += to_string(n1) + "\n";
  text += "The Standard Deviation is: " + to_string(sqrt(n1)) + "\n";
  stdDev = sqrt(n1);
  return text;
}

//Generate a random nucleotide according
// to frequency of inputed nucleotides
string processDNA::generateNuc(){
  //srand((unsigned int)time(NULL));
  //Genearte random num
  //randomNum = (rand() % 99) + 1;

  double randomNum = rand()%100 + 1;
  // cout << randomNum << endl;

// Calculate frequency of nucleotides
  if (0 < randomNum && randomNum < probA){
    return "A";


  } else if (probA < randomNum && randomNum < probT+probA){
    return "T";

  } else if (randomNum < (probC+probA+probT)){
    return "C";

  } else {
    return "G";
  }
}



//Additional DNA strings to guassian curve
string processDNA::print1000(){
  //Initialize string and the intro text
  string text = "\nAdditional 1000 DNA strings: \n";
  std::default_random_engine generator;
  std::normal_distribution<double> distribution(mean,stdDev);
  for(int i=0; i<100; ++i){
    int number = distribution(generator);
    //text += "Generate Number: " + to_string(number) + "\n";
    for(int j=0; j < number; ++j){
      text += this->generateNuc();
    }
    text += "\n";
  }
  return text;


}
