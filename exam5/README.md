# 🔁 Understanding Forward Declaration vs `#include` in C++

In this project, both abstract classes `ASpell` and `ATarget` reference each other. This creates a **circular dependency**, which must be handled carefully in C++ using a combination of:

* `class ClassName;` → **forward declaration**
* `#include "ClassName.hpp"` → **full inclusion**

---

## 🧠 Rule of Thumb

| Use Case                                        | ✅ `class X;` (Forward Declaration) | ✅ `#include "X.hpp"` (Full Definition) |
| ----------------------------------------------- | ---------------------------------- | -------------------------------------- |
| Using class `X` as a **pointer or reference**   | ✅ Yes                              | ❌ Not needed                           |
| **Calling methods** or accessing members of `X` | ❌ No                               | ✅ Yes                                  |
| **Creating or destroying** an `X` object        | ❌ No                               | ✅ Yes                                  |

---

## ✅ Application to This Project

### 📄 `ASpell.hpp`

* Uses `ATarget` as a reference only
* ✅ Use forward declaration:

```cpp
class ATarget;

class ASpell {
    ...
    void launch(const ATarget& target) const;
};
```

---

### 📄 `ASpell.cpp`

* Calls `target.getHitBySpell(*this);` (method of `ATarget`)
* ❗ Requires full class definition
* ✅ Use full include:

```cpp
#include "ASpell.hpp"
#include "ATarget.hpp"

void ASpell::launch(const ATarget& target) const {
    target.getHitBySpell(*this);
}
```

---

### 📄 `ATarget.hpp`

* Uses `ASpell` as a reference only
* ✅ Use forward declaration:

```cpp
class ASpell;

class ATarget {
    ...
    void getHitBySpell(const ASpell& spell) const;
};
```

---

### 📄 `ATarget.cpp`

* Calls `spell.getEffects()` (method of `ASpell`)
* ❗ Requires full class definition
* ✅ Use full include:

```cpp
#include "ATarget.hpp"
#include "ASpell.hpp"

void ATarget::getHitBySpell(const ASpell& spell) const {
    std::cout << _type << " has been " << spell.getEffects() << "!" << std::endl;
}
```

---

## ⚠️ Why Not Just Use `#include` Everywhere?

Avoid doing this:

* 🐌 Slower compile times
* 🔁 Risk of **circular inclusion**
* 📛 Potential multiple definition errors

💡 Use **forward declarations in headers** when possible, and include the full definition **only in `.cpp` files** when needed.

---

## 📊 Summary Table

| File          | Forward Declaration | Full Include             | Why?                              |
| ------------- | ------------------- | ------------------------ | --------------------------------- |
| `ASpell.hpp`  | `class ATarget;`    | ❌                        | Only needs a reference            |
| `ASpell.cpp`  | ❌                   | `#include "ATarget.hpp"` | Needs to call method of `ATarget` |
| `ATarget.hpp` | `class ASpell;`     | ❌                        | Only needs a reference            |
| `ATarget.cpp` | ❌                   | `#include "ASpell.hpp"`  | Needs to call method of `ASpell`  |

---

## ✅ Best Practice Summary

* Header files (`.hpp`) → use **forward declarations** where possible
* Source files (`.cpp`) → use **full `#include`** when actual method access is required

This structure keeps compilation fast, avoids circular dependency errors, and makes the codebase easier to manage.

