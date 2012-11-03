#ifndef FL_LINEAR_CHARACTERISTIC_FUNCTION_H
#define FL_LINEAR_CHARACTERISTIC_FUNCTION_H

#include "CharacteristicFunction.h"
#include "Real.h"
#include "Range.h"

class LinearCharacteristicFunction :
	public CharacteristicFunction
{
public:
	LinearCharacteristicFunction(const Point first, const Point second);
	LinearCharacteristicFunction(const Real a, const Real b, const Real k, const Real dy);
	virtual ~LinearCharacteristicFunction() {}
	virtual Real operator () (const Real val) { if(!m_range.contains(val)) return NotANumber;
												return m_dy + val * m_k; }
private:
	Range m_range;
	Real m_k;
	Real m_dy;
};

#endif // FL_LINEAR_CHARACTERISTIC_FUNCTION_H