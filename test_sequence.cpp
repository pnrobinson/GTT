#include <iostream>
#include "gtest/gtest.h"

#include "sequence.h"

using namespace seqan;

TEST(getRevComp, FindsReverseComplement) {
  seqan::DnaString myseq="ACGT";
  seqan::DnaString expected="TCGA";
  revComp(myseq);
  EXPECT_EQ(expected, myseq);
}

TEST(IndependentMethod, FindsReverseComplement2) {
  seqan::DnaString myseq="AA";
  seqan::DnaString expected="TT";
  revComp(myseq);
  EXPECT_EQ(expected, myseq);
}

// The fixture for testing class Project1. From google test primer.
class SequenceTest : public ::testing::Test {
protected:
	// You can remove any or all of the following functions if its body
	// is empty.

	SequenceTest() {
	  // do set-up work for each test here.
	}

	virtual ~SequenceTest() {
	  // You can do clean-up work that doesn't throw exceptions here.
	}

	// If the constructor and destructor are not enough for setting up
	// and cleaning up each test, you can define the following methods:
	virtual void SetUp() {
		// Code here will be called immediately after the constructor (right
		// before each test).
	}

	virtual void TearDown() {
		// Code here will be called immediately after each test (right
		// before the destructor).
	}

	// Objects declared here can be used by all tests in the test case for Project1.
	Sequence s;
};

// Test case must be called the class above
// Also note: use TEST_F instead of TEST to access the test fixture (from google test primer)
TEST_F(SequenceTest, MethodBarDoesAbc) {
  seqan::Dna5String myseq="ACGTNTTC";
  int expected=4; // first N is at position 4
  // Note we get access to Sequence s, as declared in the fixture!
  int actual=s.position_of_first_N(myseq);
  EXPECT_EQ(expected, actual);
}

// }  // namespace - could surround Project1Test in a namespace

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}
