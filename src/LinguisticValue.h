#ifndef FL_LINGUISTICVALUE_H
#define FL_LINGUISTICVALUE_H

#include "FuzzyLib.h"
#include "Real.h"
#include <list>
#include <string>
#include <memory>
#include "CharacteristicFunction.h"

class CharacteristicFunction;

class FL_EXPORT LinguisticValue
{
public:
	LinguisticValue(std::string name, CharacteristicFunction* f);
	LinguisticValue(std::string name, CharacteristicFunction::CharacteristicFunctionPtr f);
	inline LinguisticValue(const LinguisticValue& o) { *this = o; }
    LinguisticValue& operator = (const LinguisticValue& o);
    inline std::string name() const { return m_name; }
    void setCharacteristicFunction(CharacteristicFunction::CharacteristicFunctionPtr f) { m_charF = f;}
	Real intensity(const Real x) const;
    ~LinguisticValue();
private:
	std::string m_name;
	CharacteristicFunction::CharacteristicFunctionPtr m_charF;
};

typedef std::list<LinguisticValue> ListofLinguisticValues;

#endif // FL_LINGUISTICVALUE_H
