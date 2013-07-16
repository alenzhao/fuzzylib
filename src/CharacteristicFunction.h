#ifndef FL_CHARACTERISTIC_FUNCTION_H
#define FL_CHARACTERISTIC_FUNCTION_H

#include "FuzzyLib.h"
#include "Real.h"

class FL_EXPORT CharacteristicFunction
{
public:
	typedef std::shared_ptr<CharacteristicFunction> CharacteristicFunctionPtr;
	CharacteristicFunction();
	~CharacteristicFunction();
	virtual Real operator()(const Real val) { return NotANumber; }
};

#endif // FL_CHARACTERISTIC_FUNCTION_H
