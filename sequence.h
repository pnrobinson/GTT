#ifndef SEQUENCE_H_
#define SEQUENCE_H_


#include <seqan/basic.h>
#include <seqan/sequence.h>

// one free function to test
void revComp(seqan::DnaString &seq);

// one class with one function to test
class Sequence {
 public:
  const int position_of_first_N(const seqan::Dna5String &seq);  
};


#endif /* SEQUENCE_H_ */
