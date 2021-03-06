
#ifndef FL_LINGUISTIC_VARIABLE_H
#error LinguisticVariable_impl.h can be included only from LinguisticVariable.h
#endif

#include "MembershipFunction.h"

template<typename T>
LinguisticVariable<T>::LinguisticVariable(MembershipFunction<T>*	f)
	: m_membF(f)
{
}

template<typename T>
LinguisticVariable<T>::LinguisticVariable(const MembershipFunctionPtr	f)
	: m_membF(f)
{
}


template<typename T>
LinguisticVariable<T>& LinguisticVariable<T>::operator=( const LinguisticVariable<T>& src )
{
	m_values = src.m_values;
	m_membF = src.m_membF;
	return *this;
}


template<typename T>
void LinguisticVariable<T>::addValue(const LinguisticValue v, bool replaceIfNeed /*=false*/)
{
    ListofLinguisticValues::iterator it = m_values.begin();
    for(;it != m_values.end(); ++it)
        if(it->name() == v.name())
            break;

    if(it == m_values.end())
        m_values.push_back(v);
    else if(replaceIfNeed)
        *it = v;
}

template<typename T>
void LinguisticVariable<T>::removeValue(const std::string v)
{
    ListofLinguisticValues::iterator it = m_values.begin();
    for(;it != m_values.end(); ++it)
        if(it->name() == v)
            break;

    if(it != m_values.end())
        m_values.erase(it);
}

template<typename T>
ResultPair LinguisticVariable<T>::value(const T& e) const
{
    ResultPair res;
    if(m_membF != 0)
    {
        m_membF->setArg(e);
        const Real mmbrVal = (*m_membF)();
        ListofLinguisticValues::const_iterator it = m_values.cbegin();
        
		res.value	= NotANumber;
        res.text	= "undefined";
		while(it != m_values.cend() && isNan(res.value))
        {
            res.value = it->intensity(mmbrVal);
			if(!isNan(res.value))
				res.text = it->name();
            ++it;
        }
        for(;it != m_values.cend(); ++it)
        {
            const Real tmpI = it->intensity(mmbrVal);
            if(!isNan(tmpI) && tmpI > res.value)
            {
                res.value = tmpI;
                res.text = it->name();
            }
        }
    }
    
    return res;
}
