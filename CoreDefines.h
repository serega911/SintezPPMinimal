#pragma once

#define NS_CORE_START namespace Core {
#define NS_END }
#define NS_CORE Core::
#define NS_CORE_USING using namespace Core;

#define HERE std::string(__FILE__) + ": " + __FUNCTION__ + " "  + std::to_string(__LINE__)

#define SHARED_PTR(typeName, ptrName ) class typeName;\
typedef std::shared_ptr<typeName> ptrName;