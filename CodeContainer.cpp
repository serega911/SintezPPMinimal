#include "CodeContainer.h"

bool CodeContainer::add( const NS_CORE Code_p code )
{
	const NS_CORE Element_p in = *code->getInput()->getMultiLink()->getElements().begin();
	const NS_CORE Element_p out = *code->getOutput()->getMultiLink()->getElements().begin();
	Key key(in, out);

	Container& container = m_codes[key];
	bool isFinded = false;
	
	for (const auto existingCode : container)
	{
		if (existingCode->isSame(code))
		{
			return false;
		}
	}

	container.insert(code);
	return true;
}