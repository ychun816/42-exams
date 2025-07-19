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

//func
void TargetGenerator::learnTargetType(ATarget* target)
{
    std::map<std::string, ATarget*>::iterator it = _targets.find(target->getType());

    if (it == _targets.end())
    {
        _targets[target->getType()] = target->clone();
    }
}
void TargetGenerator::forgetTargetType(std::string const & targetType)
{
    std::map<std::string, ATarget*>::iterator it = _targets.find(targetType);

    if (it == _targets.end())
    {
        delete it->second;
        _targets.erase(it);
    }
}
ATarget* TargetGenerator::createTarget(std::string const & targetType)
{
    std::map<std::string, ATarget*>::iterator it = _targets.find(targetType);

    if (it != _targets.end())
    {
        return it->second->clone();
    }
    return NULL;
}
