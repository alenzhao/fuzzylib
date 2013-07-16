#ifndef FL_FUZZY_SET_H
#define FL_FUZZY_SET_H

#include <list>
#include <algorithm>
#include "FuzzyLib.h"
#include "MembershipFunction.h"

template<typename T>

class FuzzySet
{
public:

	typedef typename T ElementType;
	typedef std::list<ElementType> SetOfElements;
	typedef std::shared_ptr<MembershipFunction<T> > MembershipFunctionPtr;

	FuzzySet(	SetOfElements			members = SetOfElements(),
				MembershipFunction<T>*	membershipFunction = NULL);
	FuzzySet(			SetOfElements			members,
				const	MembershipFunctionPtr	membershipFunction);
	FuzzySet(const FuzzySet& src) { *this = src; }
	~FuzzySet() {}
	FuzzySet<T>& operator = (const FuzzySet& src);
	void add(const ElementType& member);
	void remove(const ElementType& member);
	bool contains(const ElementType& member) const;
	Real fuzzyContains(const ElementType& member) const;

private:
	MembershipFunctionPtr m_membershipFuncPtr;
	SetOfElements m_members;
};

template<typename T>
FuzzySet<T>::FuzzySet(	SetOfElements members,
						MembershipFunction<T>* membershipFunction)
	: m_members(members)
{
	m_membershipFuncPtr = std::shared_ptr<MembershipFunction<T> >(membershipFunction);
}

template<typename T>
FuzzySet<T>::FuzzySet(	SetOfElements members,
						const MembershipFunctionPtr membershipFunction)
	: m_members(members)
{
	m_membershipFuncPtr = membershipFunction;
}

template<typename T>
FuzzySet<T>& FuzzySet<T>::operator=( const FuzzySet<T>& src )
{
	m_members = src.m_members;
	m_membershipFuncPtr = src.m_membershipFuncPtr;
	return *this;
}

template<typename T>
Real FuzzySet<T>::fuzzyContains( const T& member ) const
{
	SetOfElements::const_iterator pos = std::find(m_members.cbegin(), m_members.cend(), member);
	if(pos == m_members.cend())
		return 0;
	if(!m_membershipFuncPtr)
		return 0;
	return (*m_membershipFuncPtr)(*pos);
}

template<typename T>
bool FuzzySet<T>::contains( const T& member ) const
{
	return std::find(m_members.cbegin(), m_members.cend(), member) != m_members.cend();
}

template<typename T>
void FuzzySet<T>::remove( const T& member )
{
	SetOfElements::iterator pos = std::find(m_members.begin(), m_members.end(), member);
	if(pos != m_members.end())
		m_members.erase(pos);
}

template<typename T>
void FuzzySet<T>::add( const T& member )
{
	SetOfElements::iterator pos = std::find(m_members.begin(), m_members.end(), member);
	if(pos == m_members.end())
		m_members.push_back(member);
}




#endif // FL_FUZZY_SET_H