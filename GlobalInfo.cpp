#include "GlobalInfo.h"
#include "Subset.h"
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

void GlobalInfo::init(const FreedomDegree& w, const GearSetNumer& n, const DriverNumber& d)
{
	m_isInited = true;

	m_data._w = w;
	m_data._gearSetsCount = n;
	m_data._activeDriversCount = DriverNumber(m_data._w.getValue() - 1);
	m_data._linksCount = LinkNumer(2 * m_data._gearSetsCount.getValue() - m_data._w.getValue());

	if (m_data._w == FreedomDegree(2))
	{
		m_data._frictionsCount = FrictionNumer(1);
		m_data._brakesCount = BrakeNumer(m_data._gearSetsCount.getValue());
		m_data._gearsCount = GearNumer(m_data._gearSetsCount.getValue());
	}
	else if (m_data._w == FreedomDegree(3))
	{
		m_data._frictionsCount = FrictionNumer(2);
		m_data._brakesCount = BrakeNumer(d.getValue() - m_data._frictionsCount.getValue());
		m_data._gearsCount = GearNumer( Subset<int>::count(d.getValue(), m_data._activeDriversCount.getValue()));
		/*

		const auto& settings = getSettings()->getGeneralSettings();
		m_initialData._numberOfGears = m_generalData._numberOfFrictions * m_generalData._numberOfBrakes;
		if (settings._gearChangerUseTwoFrictions)
		m_initialData._numberOfGears++;
		if (settings._gearChangerUseTwoBrakes)
		m_initialData._numberOfGears += getCombinatorics()->getSubsetsCount(m_generalData._numberOfBrakes, m_generalData._numberOfActuatedDrivingElements);

		*/
	}
	else
	{
		//Log::warning(true, "Ошибка: Некорректное количество степеней свободы!", Log::CRITICAL, HERE);
	}
	//getIOFileManager()->init();
}

const GlobalInfo::GlobalData* GlobalInfo::getData() const
{
	return m_isInited ? &m_data : nullptr;
}