#ifndef FL_LINGUISTICVALUE_H
#define FL_LINGUISTICVALUE_H

#include "Real.h"
#include <list>
#include <string>

class CharacteristicFunction;

class LinguisticValue
{
public:
	LinguisticValue(std::string name, CharacteristicFunction* f = NULL);
	inline LinguisticValue(const LinguisticValue& o) { *this = o; }
    LinguisticValue& operator = (const LinguisticValue& o);
    inline std::string name() const { return m_name; }
    void setCharacteristicFunction(CharacteristicFunction* f) { m_charF = f;}
	Real intensity(const Real x) const;
    ~LinguisticValue();
private:
	std::string m_name;
	CharacteristicFunction* m_charF;
};

typedef std::list<LinguisticValue> ListofLinguisticValues;

#endif // FL_LINGUISTICVALUE_H
