#ifndef FL_LINGUISTICVALUE_H
#define FL_LINGUISTICVALUE_H

#include "FuzzyLib.h"
#include "Real.h"
#include <list>
#include <string>

class CharacteristicFunction;

class FL_EXPORT LinguisticValue
{
public:
	LinguisticValue(std::string name, CharacteristicFunction* f = NULL, bool deleteInDestructor = true);
	inline LinguisticValue(const LinguisticValue& o) { *this = o; }
    LinguisticValue& operator = (const LinguisticValue& o);
    inline std::string name() const { return m_name; }
    void setCharacteristicFunction(CharacteristicFunction* f, bool deleteInDestructor = true) { m_charF = f;
																								m_deleteInDestructor = deleteInDestructor;}
	Real intensity(const Real x) const;
    ~LinguisticValue();
private:
	std::string m_name;
	CharacteristicFunction* m_charF;
	bool m_deleteInDestructor;
};

typedef std::list<LinguisticValue> ListofLinguisticValues;

#endif // FL_LINGUISTICVALUE_H
