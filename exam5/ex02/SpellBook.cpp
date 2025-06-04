#include "SpellBook.hpp"

SpellBook::SpellBook(){}

SpellBook::SpellBook(const SpellBook& src)
{}

SpellBook& SpellBook::operator=(const SpellBook& src)
{}

SpellBook::~SpellBook(){}

void SpellBook::learnSpell(ASpell* spellName)
{}

void SpellBook::forgetSpell(const std::string& spellName)
{}

ASpell* SpellBook::createSpell(const std::string& spellName)
{}