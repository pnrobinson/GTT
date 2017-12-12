#include "sequence.h"

#include <iostream>

seqan::Dna getRevCompl(seqan::Dna const & nucleotide){
  if (nucleotide == 'A')
    return 'T';
  if (nucleotide == 'T')
    return 'A';
  if (nucleotide == 'C')
    return 'G';
  return 'C';
}

// reverse complement "seq" in-place
// using the SeqAn "reverseComplement" function
void revComp(seqan::DnaString &seq) {
  seqan::DnaString tmp(seq);
  for (unsigned i = 0; i < length(seq); ++i)
    seq[length(seq) - 1 - i] = getRevCompl(tmp[i]);
}



const int Sequence::position_of_first_N(const seqan::Dna5String &seq) {
  for (unsigned int i=0;i<length(seq);++i) {
    if (seq[i]=='N') return i;
  }
  return -1;
}

