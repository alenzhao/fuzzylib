#ifndef FL_TRAPESOID_CHARACTERISTIC_FUNCTION
#define FL_TRAPESOID_CHARACTERISTIC_FUNCTION

#include "FuzzyLib.h"
#include "CharacteristicFunction.h"
#include "Real.h"
#include "LinearCharacteristicFunction.h"

class FL_EXPORT TrapesoidCharacteristicFunction :
	public CharacteristicFunction
{
public:
	TrapesoidCharacteristicFunction(const Real a, const Point b, const Real c, const Real d);
	virtual ~TrapesoidCharacteristicFunction();
	virtual Real operator () (const Real val);
private:
	Real m_a;
	Real m_c;
	Real m_d;
	Point m_b;
	LinearCharacteristicFunction* m_left;
	LinearCharacteristicFunction* m_center;
	LinearCharacteristicFunction* m_right;
};

#endif