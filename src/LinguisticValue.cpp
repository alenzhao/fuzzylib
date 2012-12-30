#include "LinguisticValue.h"
#include "CharacteristicFunction.h"


LinguisticValue::LinguisticValue(std::string name, CharacteristicFunction* f/*= 0*/, bool deleteInDestructor/* = true*/)
	: m_name(name)
	, m_charF(f)
	, m_deleteInDestructor(deleteInDestructor)
{
}


LinguisticValue::~LinguisticValue()
{
	if(m_deleteInDestructor)
		delete m_charF;
}

LinguisticValue& LinguisticValue::operator = (const LinguisticValue& o)
{
    this->m_name = o.m_name;
    this->m_charF = o.m_charF;
	this->m_deleteInDestructor = o.m_deleteInDestructor;
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
