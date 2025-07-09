#include "TargetGenerator.hpp"

TargetGenerator::~TargetGenerator()
{
    for (std::map<std::string, ATarget*>::iterator it = _targets.begin(); it != _targets.end(); ++it)
        delete it->second;
        this->_targets.clear();
}

void TargetGenerator::learnTargetType(ATarget* targetType)
{
    if (targetType && _targets.find(targetType->getType()) == _targets.end())
        _targets[targetType->getType()] = targetType->clone();
}

void TargetGenerator::forgetTargetType(const std::string& targetType)
{
    std::map<std::string, ATarget*>::iterator it = _targets.find(targetType);
    if (it != _targets.end())
    {
        delete it->second;
        _targets.erase(it);
    }
}

ATarget* TargetGenerator::createTarget(const std::string& targetType)
{
    std::map<std::string, ATarget*>::iterator it = _targets.find(targetType);
    if (it != _targets.end())
        return (it->second->clone());
    return NULL;
}