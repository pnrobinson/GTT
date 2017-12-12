#include <iostream>
#include "sequence.h"

#include <seqan/basic.h>
#include <seqan/file.h>
#include <seqan/modifier.h>

using namespace std;

int main() {
  cout << "Get rev comp of sequence ACCGG" << endl;
  seqan::DnaString seq="ACCGG";
  cout << "1. " << seq <<endl;
  revComp(seq);
  cout << "2. " << seq <<endl;
  Sequence s;
  seqan::Dna5String seq2="ACGNT";
  int pos = s.position_of_first_N(seq2); 
  cout << "Position of first N in " << seq2 << " is " << (1+pos) << endl;
}
