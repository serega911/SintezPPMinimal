#include "GlobalInfo.h"

NS_CORE_USING

GlobalInfo::GlobalInfo()
: m_isInited( false )
{
}

GlobalInfo* Core::GlobalInfo::getInstance()
{
	static GlobalInfo singleton;
	return &singleton;
}

void GlobalInfo::init( const GlobalData& data )
{
	m_data = data;
	m_isInited = true;
}

const GlobalInfo::GlobalData* GlobalInfo::getData() const
{
	return m_isInited ? &m_data : nullptr;
}