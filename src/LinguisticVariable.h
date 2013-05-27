#ifndef FL_LINGUISTIC_VARIABLE_H
#define FL_LINGUISTIC_VARIABLE_H

#include "FuzzyLib.h"
#include "MembershipFunction.h"
#include "LinguisticValue.h"
#include "ResultPair.h"

#include <string>

/*
	NOTE ABOUT EXPORTING SYMBOLS ON WINDOWS:
	The LinguisticVariable class is template, so it's implementation is fully
	in header file, so we do not need to export it's functions
*/

template<typename T>
class LinguisticVariable
{
public:
	typedef std::shared_ptr<MembershipFunction<T> > MembershipFunctionPtr;
	explicit LinguisticVariable(MembershipFunction<T>* f);
	explicit LinguisticVariable(const MembershipFunctionPtr	f = MembershipFunctionPtr());
	LinguisticVariable(const LinguisticVariable& src) { *this = src; }

	LinguisticVariable& operator = (const LinguisticVariable& src);
    void addValue(const LinguisticValue v, const bool replaceIfNeed = false);
    void removeValue(const std::string v);
    inline void removeValue(const LinguisticValue& v) { removeValue(v.name()); }
    inline const ListofLinguisticValues values() const { return m_values; }
    ResultPair value(const T&) const;
private:
	MembershipFunctionPtr	m_membF; 
	ListofLinguisticValues	m_values;
};

#include "LinguisticVariable_impl.h"

#endif // FL_LINGUISTIC_VARIABLE_H
