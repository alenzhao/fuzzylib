#ifndef FL_LINGUISTIC_VARIABLE_H
#define FL_LINGUISTIC_VARIABLE_H

#include "MembershipFunction.h"
#include "LinguisticValue.h"
#include "ResultPair.h"

#include <string>

template<typename T>
class LinguisticVariable
{
public:
	explicit LinguisticVariable(MembershipFunction<T>* f);
    void addValue(const LinguisticValue v, const bool replaveIfNeed = false);
    void removeValue(const std::string v);
    inline void removeValue(const LinguisticValue& v) { removeValue(v.name()); }
    inline const ListofLinguisticValues values() const { return m_values; }
    ResultPair value(const T&);
private:
	MembershipFunction<T>* m_membF;
	ListofLinguisticValues m_values;
};

#include "LinguisticVariable_impl.h"

#endif // FL_LINGUISTIC_VARIABLE_H