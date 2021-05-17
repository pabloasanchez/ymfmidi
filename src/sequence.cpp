#include <cstdio>

#include "sequence.h"
#include "sequence_mid.h"
#include "sequence_mus.h"

// ----------------------------------------------------------------------------
Sequence::~Sequence() {}

// ----------------------------------------------------------------------------
Sequence* Sequence::load(const char *path)
{
	FILE *file = fopen(path, "rb");
	if (!file) return nullptr;
	
	Sequence *seq = nullptr;
	
	if (SequenceMUS::isValid(file))
		seq = new SequenceMUS(file);
	else if (SequenceMID::isValid(file))
		seq = new SequenceMID(file);
	
	fclose(file);
	return seq;
}
