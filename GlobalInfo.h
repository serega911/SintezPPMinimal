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
		BrakeNumer								_brakesCount;
		FrictionNumer							_frictionsCount;
		LinkNumer								_linksCount;
		DriverNumber							_activeDriversCount;
		GearNumer								_gearsCount;
	};

	static GlobalInfo*							getInstance();
	void										init( const FreedomDegree& w, const GearSetNumer& n, const DriverNumber& d );
	const GlobalData*							getData() const;

private:

	GlobalData									m_data;
	bool										m_isInited;

	GlobalInfo();
	GlobalInfo( const GlobalInfo& ) = delete;

};

NS_END