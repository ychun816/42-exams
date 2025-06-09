#include "TargetGenerator.hpp"


//constructor
TargetGenerator::TargetGenerator(){}
TargetGenerator:: ~TargetGenerator()
{
    for (std::map<std::string, ATarget*>::iterator it = _targets.begin(); it != _targets.end(); ++it)
        delete it->second;
    //this->_targets.clear();
}


//put target key/value into map
void TargetGenerator::learnTargetType(ATarget* target)
{
    if (target && _targets.find(target->getType()) == _targets.end())
        _targets[target->getType()] = target->clone();
}

//delete target value
//erase target pointer (it)
void TargetGenerator::forgetTargetType(const std::string& targetType)
{
    std::map<std::string, ATarget*>::iterator it = _targets.find(targetType);
    if (it != _targets.end())
        delete it->second;
    _targets.erase(it);
}

//return target value
ATarget* TargetGenerator::createTarget(const std::string& targetType)
{
    std::map<std::string, ATarget*>::iterator it = _targets.find(targetType);
    if (it != _targets.end())
        return (it->second->clone());
    return NULL;
}