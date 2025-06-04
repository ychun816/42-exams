#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(){}

//delete one by one
TargetGenerator::~TargetGenerator()
{
    for (std::map<std::string, ATarget*>::iterator it = _targets.begin(), it != _targets.end(), ++it)
        delete it->second;
    //this->_targets.clear();
}

//assign &create clone
void TargetGenerator::learnTargetType(ATarget* target)
{
    if (target && _targets.find(target->getType()) == _targets.end())
        _targets[target->getType()] = target->clone();
}

void TargetGenerator::forgetTargetType(const std::string& targetType)
{
    std::map<std::string, ATarget*>::iterator it = _targets.find(targetType);
    if (it != _targets.end())
    {
        delete it->second;
        targets.erase(it);
    }
}

ATarget* TargetGenerator::createTarget(const std::string& targetType)
{
    std::map<std::string, ATarget*>::iterator it = _targets.find(targetType);
    if (it != _targets.end())
        return (it->second->clone());
    return NULL;
}