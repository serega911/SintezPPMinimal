#pragma once

#include "CoreDefines.h"
#include "Types.h"

NS_CORE_START

class GlobalInfo
{
public:

	struct GlobalData
	{
		FreedomDegree							_w;
		GearSetNumer							_gearSetsCount;
	};

	static GlobalInfo*							getInstance();
	void										init( const GlobalData& data );
	const GlobalData*							getData() const;

private:

	GlobalData									m_data;
	bool										m_isInited;

	GlobalInfo();
	GlobalInfo( const GlobalInfo& ) = delete;

};

NS_END