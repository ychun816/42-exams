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


-------

Great! Here's a polished GitHub-friendly README section you can directly copy and paste into your project. It includes:

* ✅ Markdown formatting with code blocks
* 🌐 Dual-language (English + Traditional Chinese)
* 🧪 Practical examples with file references
* 🔗 Optional section for navigation if you want to organize a larger README

---

## 🔁 Understanding Forward Declarations and `#include` in C++

🔁 理解 C++ 中的前向宣告與 `#include`

> This project contains circular dependencies between `ASpell` and `ATarget`, which require proper separation of interface (`.hpp`) and implementation (`.cpp`) using forward declarations and full includes.
> 本專案中 `ASpell` 和 `ATarget` 彼此參考，必須適當使用「前向宣告」與「完整引入」來避免循環依賴錯誤。

---

### 📘 What’s the Problem? 問題是什麼？

Circular references occur when:

* `ASpell` uses methods of `ATarget`
* `ATarget` also uses methods of `ASpell`

This can’t be resolved by the compiler unless handled with care.

---

### 🧠 Rules: When to Use What?

何時使用 `class X;` 或 `#include "X.hpp"`？

| Use Case 📌                       | ✅ `class X;` (Forward Decl.) | ✅ `#include "X.hpp"` (Full Include) | 中文說明             |
| --------------------------------- | ---------------------------- | ----------------------------------- | ---------------- |
| Only use pointer/reference to `X` | ✅ Yes                        | ❌ No                                | 只傳參考或指標，不呼叫成員    |
| Call methods or access members    | ❌ No                         | ✅ Yes                               | 需要完整型別來存取方法或屬性   |
| Create or delete `X`              | ❌ No                         | ✅ Yes                               | 建構／銷毀物件也需要知道完整定義 |

---

### 📁 Project-Specific Usage 專案應用情境

#### ✅ ASpell.hpp

```cpp
// only needs forward declaration
class ATarget;

class ASpell {
public:
    void launch(const ATarget& target) const; // only reference
};
```

#### ✅ ASpell.cpp

```cpp
#include "ASpell.hpp"
#include "ATarget.hpp" // needs full definition

void ASpell::launch(const ATarget& target) const {
    target.getHitBySpell(*this); // calls method
}
```

#### ✅ ATarget.hpp

```cpp
class ASpell;

class ATarget {
public:
    void getHitBySpell(const ASpell& spell) const; // only reference
};
```

#### ✅ ATarget.cpp

```cpp
#include "ATarget.hpp"
#include "ASpell.hpp" // full definition needed

void ATarget::getHitBySpell(const ASpell& spell) const {
    std::cout << _type << " has been " << spell.getEffects() << "!" << std::endl;
}
```

---

### 📊 Summary Table 總結對照表

| File        | Needs `class X;`? | Needs `#include "X.hpp"`? | Why 為什麼？                               |
| ----------- | ----------------- | ------------------------- | -------------------------------------- |
| ASpell.hpp  | ✅ Yes             | ❌ No                      | Only uses ATarget as reference         |
| ASpell.cpp  | ❌ No              | ✅ Yes                     | Calls ATarget method (`getHitBySpell`) |
| ATarget.hpp | ✅ Yes             | ❌ No                      | Only uses ASpell as reference          |
| ATarget.cpp | ❌ No              | ✅ Yes                     | Calls ASpell method (`getEffects`)     |

---

### ⚠️ Why Not Just `#include` Everything?

為什麼不直接全部 `#include`？

* ❌ Slower build time 編譯變慢
* ❌ Multiple inclusion issues 多重定義問題
* ❌ Harder to manage project dependencies 維護困難

✅ Best Practice:

* Use `class X;` in headers when possible
* Use `#include "X.hpp"` in `.cpp` when needed

---

### 🔗 Navigation (Optional)

You may want to add this to the top of your README if you're including this section in a longer document:

```md
## Table of Contents
- [Project Overview](#project-overview)
- [Class Design](#class-design)
- [Usage of Forward Declaration](#-understanding-forward-declarations-and-include-in-c)
- [Build Instructions](#build-instructions)
```

---
