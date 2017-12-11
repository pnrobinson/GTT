#ifndef SEQUENCE_H_
#define SEQUENCE_H_


#include <seqan/basic.h>
#include <seqan/sequence.h>

seqan::Dna getRevComp(seqan::DnaString &seq);



class Sequence {
 public:
  const int position_of_first_N(const seqan::Dna5String &seq);  
};


#endif /* SEQUENCE_H_ */
