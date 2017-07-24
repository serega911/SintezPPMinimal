#pragma once

#include "CoreDefines.h"
#include "IObject.h"

NS_CORE_START


#define USER_DEFINED_TYPE_INTEGRAL( typeName, buildInType)																						\
class typeName : public IObject																													\
{																																				\
private:																																		\
	buildInType m_value;																														\
public:																																			\
	explicit					typeName(const buildInType value): m_value(value)			{}													\
								typeName(): m_value(0)										{}													\
	inline const buildInType&	getValue() const											{ return m_value; }									\
	inline friend typeName		operator-( const typeName& obj1, const typeName& obj2 )		{ return typeName(obj1.m_value - obj2.m_value); }	\
	inline friend typeName		operator+( const typeName& obj1, const typeName& obj2 )		{ return typeName(obj1.m_value + obj2.m_value); }	\
	inline friend bool			operator<( const typeName& obj1, const typeName& obj2 )		{ return obj1.m_value < obj2.m_value; }				\
	inline friend bool			operator>( const typeName& obj1, const typeName& obj2 )		{ return obj1.m_value > obj2.m_value; }				\
	inline friend bool			operator==( const typeName& obj1, const typeName& obj2 )	{ return obj1.m_value == obj2.m_value; }			\
	inline friend bool			operator<=( const typeName& obj1, const typeName& obj2 )	{ return !(obj1 > obj2); }							\
	inline friend bool			operator>=( const typeName& obj1, const typeName& obj2 )	{ return !(obj1 < obj2); }							\
	inline friend bool			operator!=( const typeName& obj1, const typeName& obj2 )	{ return !(obj1 == obj2); }							\
	inline buildInType			getAbs() const												{ return m_value >= 0 ? m_value : - m_value ; }		\
	inline const typeName&		operator=( const buildInType& value )						{ m_value = value; return *this; }					\
	inline const typeName&		operator=( const typeName& obj2 )							{ m_value = obj2.m_value; return *this; }			\
	inline const typeName&		operator++( )												{ m_value++; return *this; }						\
	inline const typeName&		operator--( )												{ m_value--; return *this; }						\
};

#define USER_DEFINED_TYPE_FLOATING( typeName, buildInType)																						\
class typeName : public IObject																													\
{																																				\
private:																																		\
	buildInType m_value;																														\
public:																																			\
	explicit					typeName(const buildInType value): m_value(value)			{}													\
								typeName(): m_value(0)										{}													\
	inline const buildInType&	getValue() const											{ return m_value; }									\
	inline friend typeName		operator-( const typeName& obj1, const typeName& obj2 )		{ return typeName(obj1.m_value - obj2.m_value); }	\
	inline friend typeName		operator+( const typeName& obj1, const typeName& obj2 )		{ return typeName(obj1.m_value + obj2.m_value); }	\
	inline friend bool			operator<( const typeName& obj1, const typeName& obj2 )		{ return obj1.m_value < obj2.m_value; }				\
	inline friend bool			operator>( const typeName& obj1, const typeName& obj2 )		{ return obj1.m_value > obj2.m_value; }				\
	inline friend bool			operator==( const typeName& obj1, const typeName& obj2 )	{ return abs(obj1.m_value - obj2.m_value) < 0.00001; }\
	inline friend bool			operator<=( const typeName& obj1, const typeName& obj2 )	{ return !(obj1 > obj2); }							\
	inline friend bool			operator>=( const typeName& obj1, const typeName& obj2 )	{ return !(obj1 < obj2); }							\
	inline friend bool			operator!=( const typeName& obj1, const typeName& obj2 )	{ return !(obj1 == obj2); }							\
	inline buildInType			getAbs() const												{ return abs( m_value ); }							\
	inline const typeName&		operator=( const buildInType& value )						{ m_value = value; return *this; }					\
	inline const typeName&		operator=( const typeName& obj2 )							{ m_value = obj2.m_value; return *this; }			\
};

USER_DEFINED_TYPE_INTEGRAL( GearSetNumer, int );
USER_DEFINED_TYPE_INTEGRAL( FrictionNumer, int );
USER_DEFINED_TYPE_INTEGRAL( BrakeNumer, int );
USER_DEFINED_TYPE_INTEGRAL( DriverNumber, int);
USER_DEFINED_TYPE_INTEGRAL( LinkNumer, int );
USER_DEFINED_TYPE_INTEGRAL( GearNumer, int );
USER_DEFINED_TYPE_INTEGRAL( FreedomDegree, int );

#define LOOP_UP(type, varName, begin, end) for (type varName(begin); varName <= type(end); ++varName)
#define GEAR_SET_NUM_LOOP_UP(varName, N) LOOP_UP (GearSetNumer, varName, 1, N)

NS_END