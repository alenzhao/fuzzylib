#ifndef FL_FUZZY_SET_H
#define FL_FUZZY_SET_H

#include "MembershipFunction.h"
#include <set>

template<T>
class FuzzySet:
{
public:
	FuzzySet(std::set<T> members = std::set<T>(), MembershipFunctionPtr<T> memnberShipFunction = MembershipFunctionPtr());
	~FuzzySet();
	void add(const T& member);
	void remove(const T& member);
	bool contains(const T& member) const;
	double fuzzyContains(const T& member) const;
private:
	MembershipFunctionPtr<T> m_membershipFuncPtr;
	std::set<T> m_members;
};

template<T>
double FuzzySet<>::fuzzyContains( const T& member ) const
{
	std::set<T>::const_iterator mmbr = m_members.find(member);
	if(mmbr == m_members.end())
		return 0;
	if(!m_membershipFuncPtr)
		return 0;
	return (*m_membershipFuncPtr)(member);
}

template<T>
bool FuzzySet<>::contains( const T& member ) const
{
	m_members.find(member) != m_members.cend();
}

template<T>
void FuzzySet<>::remove( const T& member )
{
	m_members.erase(member);
}

template<T>
void FuzzySet<T>::add( const T& member )
{
	m_members.insert(member);
}




#endif // FL_FUZZY_SET_H