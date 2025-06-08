#include "Warlock.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"

int main() {
  Warlock richard("Richard", "the Titled");

  Dummy bob;
  Fwoosh* fwoosh = new Fwoosh();

  richard.learnSpell(fwoosh);

  richard.introduce();
  richard.launchSpell("Fwoosh", bob);

  richard.forgetSpell("Fwoosh");
  richard.launchSpell("Fwoosh", bob);
}

/*
Expected output:
Richard: This looks like another boring day.
Richard: I am Richard, the Titled!
Target Practice Dummy has been fwooshed!
Richard: My job here is done!
*/