#pragma once

#include <vector>

#include "UnitBase.h"
#include "Element.h"
#include "Code.h"
#include "GlobalInfo.h"
#include "CodeContainer.h"

SHARED_PTR(Code, Code_p)
class Code : public NS_CORE Code
{

public:
	std::vector<NS_CORE Element_p> getElementsForFrictions() const
	{
		const auto & multilinks = NS_CORE Code::getMultiLinks();
		std::vector<NS_CORE Element_p> ret;

		ret.reserve(multilinks.size());
		for (const auto& multilink : multilinks)
			ret.push_back(*multilink->getElements().begin());
		return ret;
	}

	std::vector<NS_CORE Element_p> getElementsForBrakes() const
	{
		const auto & multilinks = NS_CORE Code::getMultiLinks();
		std::vector<NS_CORE Element_p> ret;

		const NS_CORE MultiLink_p inputMultiLink = NS_CORE Code::getInput()->getMultiLink();
		const NS_CORE MultiLink_p outputMultiLink = NS_CORE Code::getOutput()->getMultiLink();

		ret.reserve(multilinks.size());
		for (const auto& multilink : multilinks)
		{
			if (multilink != inputMultiLink && multilink != outputMultiLink)
			ret.push_back(*multilink->getElements().begin());
		}
			
		return ret;
	}

	static Code_p create()
	{
		return Code_p(new Code);
	}

	Code_p clone() const
	{
		return Code_p(new Code(*this));
	}

	void fill()
	{
		NS_CORE GearSetNumer max = NS_CORE GlobalInfo::getInstance()->getData()->_gearSetsCount;

		for (NS_CORE GearSetNumer gearSet(1); gearSet <= max; ++gearSet)
		{
			for (const auto& eelem : NS_CORE c_centraleElements)
			{
				const auto& multilinks = getMultiLinks();
				auto elem = NS_CORE Element::create(eelem, gearSet);
				bool isFinded = false;

				for (const auto ml : multilinks)
				{
					if (ml->isContain(elem))
						isFinded = true;
				}

				if (!isFinded)
				{
					addElement(elem);
				}
			}
		}
	}
};

class UnitGenerate : public NS_CORE UnitBase
{
	typedef std::pair<NS_CORE Element_p, NS_CORE Element_p> Link;
	
	std::vector<Link>							m_links;
	CodeContainer								m_container;

	void										prepareLinks();
	void										generateInOut();
	void										generateLinks(const Code_p& code);
	void										generateFrictions(const Code_p& code);
	void										generateBrakes(const Code_p& code);
	void										checkAndFinish(const Code_p& code);

public:

	virtual void								run() override;
	virtual bool								checkRequirements() const override;

};