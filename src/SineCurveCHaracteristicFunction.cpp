#include "SineCurveCharacteristicFunction.h"


SineCurveCharacteristicFunction::SineCurveCharacteristicFunction( Real dy /*= 0*/, Real dx /*= 0*/, Real yScale /*= 0*/, Real xScale /*= 0*/ )
	: m_dy(dy)
	, m_dx(dx)
	, m_scaleX(xScale)
	, m_scaleY(yScale)
{

}


SineCurveCharacteristicFunction::~SineCurveCharacteristicFunction()
{
}
