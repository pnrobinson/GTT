#include "sequence.h"

#include <iostream> 

// reverse complement "seq" in-place
// using the SeqAn "reverseComplement" function
seqan::Dna getRevComp(seqan::DnaString &seq) {
  reverseComplement(seq);
}



const int Sequence::position_of_first_N(const seqan::Dna5String &seq) {
  for (unsigned int i=0;i<length(seq);++i) {
    if (seq[i]=='N') return i;
  }
  return -1;
}

