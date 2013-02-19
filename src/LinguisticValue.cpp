#include "LinguisticValue.h"
#include "CharacteristicFunction.h"


LinguisticValue::LinguisticValue(std::string name, CharacteristicFunction* f/*= 0*/)
	: m_name(name)
	, m_charF(f)
{
}


LinguisticValue::~LinguisticValue()
{}

LinguisticValue& LinguisticValue::operator = (const LinguisticValue& o)
{
    this->m_name = o.m_name;
    this->m_charF = o.m_charF;
    return *this;
}

Real LinguisticValue::intensity(const Real x) const
{
    Real r = NotANumber;
    if(m_charF != 0)
    {
        r = (*m_charF)(x);
    }
    return r;
}
