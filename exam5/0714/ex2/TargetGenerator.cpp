#include "TargetGenerator.hpp"

TargetGenerator::~TargetGenerator()
{
    std::map<std::string, ATarget*>::iterator it = _targets.begin();
    std::map<std::string, ATarget*>::iterator itend = _targets.end();

    for (; it != itend; ++it)
    {
        delete it->second;
    }
    _targets.clear();
}


void TargetGenerator::learnTargetType(ATarget* target)
{
    std::map<std::string, ATarget*>::iterator it = _targets.find(target->getType());
    
    if (target && it == _targets.end())
    {
        _targets[target->getType()] = target->clone();
    }

}

void TargetGenerator::forgetTargetType(std::string const & spellName)
{
    std::map<std::string, ATarget*>::iterator it = _targets.find(spellName);

    if (it != _targets.end())
    {
        delete it->second;
        _targets.erase(it);
    }
}

ATarget* TargetGenerator::createTarget(std::string const & spellName)
{
    std::map<std::string, ATarget*>::iterator it = _targets.find(spellName);

    if (it != _targets.end())
    {
        return (it->second->clone());
    }
    return NULL;
}
