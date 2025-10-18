#  RegexQL: A Visual Query Language for Pattern Matching

---

##  Overview

**RegexQL** is a mini-compiler project developed under the subject **Compiler Design**.  
It converts **natural language queries** into **regular expressions (regex)** and executes them on a given text.

For example:

synatx for query 
[action][pattern][specifier][value]


###  **Supported Actions**
- `find` → search for pattern  
- `match` → extract all matching patterns  

###  **Supported Patterns**
- `email`
- `phone number`
- `url`
- `digit`
- `date`
- `word`

###  **Optional Specifiers**
- `starting with`
- `ending with`
- `containing`

---

##  Example Query and Text

### **Example 1**

**Query:**
find email in text


**Text:**
My email is compiler123@gmail.com
 and alternate is test@yahoo.in


**Output:**
Matches found:
compiler123@gmail.com
test@yahoo.in


---

### **Example 2**

**Query:**
match phone number starting with +91


**Text:**
My contacts are +919876543210 and 0801234567


**Output:**
Matches found:
+919876543210


---

## 📁 Folder Structure

```text
RegexQL/
│
├── Makefile
│
└── src/
    ├── main.cpp
    ├── lexer.cpp
    ├── parser.cpp
    ├── translator.cpp
    ├── executor.cpp
    ├── lexer.h
    ├── parser.h
    ├── translator.h
    ├── executor.h
    └── utils.h
```
    
---

##  Working of Each Phase

| **Phase** | **Input** | **Output** | **Description** |
|------------|------------|-------------|-----------------|
| **Lexer** | Raw query (string) | Tokens (words/phrases) | Breaks user query into tokens |
| **Parser** | Tokens | Query object | Checks syntax & extracts meaning |
| **Translator** | Query object | Regex pattern | Converts query into regex |
| **Executor** | Regex + Text | Matches | Applies regex & shows results |

---

##  Example Compilation Flow

**Query:**
find email in text


| **Phase** | **Input** | **Output** |
|------------|------------|-------------|
| Lexer | `"find email in text"` | `["find", "email", "in", "text"]` |
| Parser | Tokens | `Query{action=FIND, pattern=EMAIL}` |
| Translator | Query | `[\w\.-]+@[\w\.-]+\.\w+` |
| Executor | Regex + Text | Matches all email addresses |

---

##  Why Separate `.h` and `.cpp` Files?

| File Type | Purpose |
|------------|----------|
| `.h` (Header File) | Declares functions, structures, and interfaces |
| `.cpp` (Source File) | Implements the actual logic |

**Advantages:**
- Improves **modularity** and **readability**  
- Simplifies **debugging** and **testing**  
- Allows **independent compilation**  
- Promotes **reusability** across files  

---

##  Conclusion

This project demonstrates how compiler design concepts can be applied to **natural language processing**.  
RegexQL bridges the gap between **human-understandable queries** and **machine-executable regex patterns**.  
It serves as a practical example of **Lexical Analysis, Parsing, Semantic Translation, and Execution**  
within a single, modular system built using **C++**.

---

## 👨‍💻 Team Members

| Name | Student ID |
|------|-------------|
| **Mehul Goyal** | *2023UCP1603* |
| **Vaibhav Garg** | *2023UCP1659* |

---

## 🧑‍🏫 Submitted To

**Mr. Dinesh Gopalani**  
*Department of Computer Science*  
*Under the course: Compiler Design*

---

> 🏁 *RegexQL — Making Regex Human Again!*
