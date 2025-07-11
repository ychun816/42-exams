#include "TargetGenerator.hpp"

TargetGenerator::~TargetGenerator()
{
    std::map<std::string, ATarget*>::iterator it = _targets.begin();
    std::map<std::string, ATarget*>::iterator itend = _targets.end();

    for (; it != itend; ++it)
        delete it -> second;
    _targets.clear();
}

void TargetGenerator::learnTargetType(ATarget* target)
{
    std::map<std::string, ATarget*>::iterator it = _targets.find(target->getType());
    if (target && it == _targets.end()) //key NOT found
        _targets[target->getType()] = target->clone();
}

void TargetGenerator::forgetTargetType(std::string const & targetType)
{
    std::map<std::string, ATarget*>::iterator it = _targets.find(targetType);
    
    if (it != _targets.end()) //key found
    {
        delete it->second; // Free the memory
        _targets.erase(it); //remove entry
    }
}

ATarget* TargetGenerator::createTarget(std::string const & targetType)
{
    std::map<std::string, ATarget*>::iterator it = _targets.find(targetType);

    if (it != _targets.end())
        return it->second->clone();
    return NULL;
}


/*
if (it == _targets.end())
    // The key is NOT found

if (it != _targets.end())
    // The key IS found


*/