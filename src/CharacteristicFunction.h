#ifndef FL_CHARACTERISTIC_FUNCTION_H
#define FL_CHARACTERISTIC_FUNCTION_H

#include "Real.h"

class CharacteristicFunction
{
public:
	CharacteristicFunction();
	~CharacteristicFunction();
	virtual Real operator()(const Real val) = 0;
};

#endif // FL_CHARACTERISTIC_FUNCTION_H
