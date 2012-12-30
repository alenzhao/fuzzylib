#ifndef FL_MEMBERSHIP_FUNCTION_H
#define FL_MEMBERSHIP_FUNCTION_H

#include "FuzzyLib.h"
#include "Real.h"

#define DECLARE_FUNCTIONAL inline Real operator()(const T arg) { setArg(arg);	return operator()(); } virtual Real operator()();
#define DECLARE_INLINE_FUNCTIONAL inline Real operator()(const T arg) { setArg(arg);	return operator()(); } inline virtual Real operator()()

#define BEGIN_FUNCTIONAL_IMPLEMENTATION(Class) BEGIN_FUNCTIONAL_IMPLEMENTATION_A(Class, arg)
#define BEGIN_FUNCTIONAL_IMPLEMENTATION_A(Class, ArgName)	template<typename T> \
															Real Class##<T>::operator()() \
															{ \
																const ArgumentProvider::Type& ArgName  = this->arg();

#define END_FUNCTIONAL_IMPLEMENTATION END_FUNCTIONAL_IMPLEMENTATION_A
#define END_FUNCTIONAL_IMPLEMENTATION_A }

/*
	NOTE ABOUT EXPORTING SYMBOLS ON WINDOWS:
	The MembershipFunction class is template, so it's implementation is fully
	in header file, so we do not need to export it's functions
*/

template<typename T>
class MembershipFunction
{
public:
	typedef MembershipFunction<T> ArgumentProvider;
	typedef T Type;
	MembershipFunction(){};
	virtual ~MembershipFunction(){};
    void setArg(const T arg);
	
	virtual Real operator()() = 0;
    T& arg();
	inline Real operator()(const T arg)
	{
		setArg(arg);
		return operator()();
	}
protected:
    T m_arg;
};

template<typename T>
void MembershipFunction<T>::setArg(const T arg)
{
    m_arg = arg;
}

template<typename T>
T& MembershipFunction<T>::arg()
{
    return m_arg;
}

#endif // FL_MEMBERSHIP_FUNCTION_H
