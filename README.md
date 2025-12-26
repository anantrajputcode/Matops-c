# MATOPS - Matrix Operations Calculator

A comprehensive command-line matrix operations calculator written in C, featuring password protection, multiple matrix operations, and an intuitive menu-driven interface.

**Author:** Anant Rajput  
**Version:** 4.1.1  
**Last Updated:** December 25, 2025

---

## 📋 Table of Contents

- [Features](#-features)
- [Operations Supported](#-operations-supported)
- [Prerequisites](#-prerequisites)
- [Installation](#-installation)
- [Usage](#-usage)
- [Examples](#-examples)
- [System Settings](#-system-settings)
- [Error Handling](#-error-handling)
- [Limitations](#-limitations)
- [Future Enhancements](#-future-enhancements)
- [Contributing](#-contributing)
- [License](#-license)

---

## ✨ Features

- **🔐 Password Protected:** Secure login system with 5-attempt limit and persistent password storage
- **💾 Password Persistence:** Password saved to `password.txt` file (default: `12345`)
- **📊 Seven Matrix Operations:** Complete suite of linear algebra operations
- **✅ Input Validation:** Comprehensive dimension and compatibility checks
- **🎯 User-Friendly Interface:** Clear, menu-driven navigation
- **⚙️ System Settings:** Password management and program information
- **🧹 Screen Management:** Clear screen functionality for better organization
- **💾 Memory Efficient:** Dynamic memory allocation using VLAs
- **🔄 Session Persistence:** Continue operations without restarting
- **🔒 Security Features:** Forceful eviction after failed password change attempts

---

## 🔢 Operations Supported

### 1. Matrix Multiplication
- Multiplies two matrices A[r₁×c₁] and B[r₂×c₂]
- Validates compatibility (c₁ must equal r₂)
- Supports any valid matrix dimensions
- **Input Type:** Integer
- **Output:** Result matrix of size r₁×c₂

### 2. Determinant Calculation
- Computes determinants using cofactor expansion
- **Supported sizes:** 1×1, 2×2, 3×3
- Validates square matrix requirement
- **Input Type:** Integer
- **Output:** Integer determinant value

### 3. Matrix Inverse
- Calculates inverse using adjugate method
- **Supported sizes:** 1×1, 2×2, 3×3
- Checks for singular matrices (det = 0)
- **Input Type:** Float
- **Output:** Floating-point inverse (2 decimal places)

### 4. Characteristic Equation
- Derives characteristic polynomial using trace and determinant
- **Supported sizes:** 2×2, 3×3
- **Input Type:** Integer
- **Output format:**
  - 2×2: `λ² - (trace)λ + det`
  - 3×3: `λ³ - (trace)λ² + (sum of minors)λ - det`

### 5. Eigenvalues
- Calculates eigenvalues using quadratic formula
- **Supported sizes:** 2×2 only
- Handles real eigenvalues (complex eigenvalues display as NaN)
- **Input Type:** Integer
- **Output:** Both eigenvalues (floating-point)

### 6. Eigenvectors
- Computes eigenvectors corresponding to eigenvalues
- **Supported sizes:** 2×2 only
- Uses simplified formula: `[a₁₂, λ - a₁₁]ᵀ`
- **Input Type:** Integer
- **Output:** Two eigenvectors in column form

### 7. Transpose
- Swaps rows and columns
- **Supported sizes:** Any dimensions
- **Input Type:** Integer
- **Output:** Transposed matrix

---

## 🛠️ Prerequisites

- **C Compiler:** GCC 4.8+ or any C99-compatible compiler
- **Operating System:** Linux/Unix (uses `system("clear")`)
- **Math Library:** Standard C math library (`-lm` flag required)
- **Knowledge:** Basic understanding of linear algebra
- **File Permissions:** Write access for `password.txt` file

---

## 📦 Installation

### Clone the Repository
```bash
git clone https://github.com/yourusername/matops.git
cd matops
```

### Compile the Program
```bash
gcc matops.c -o matops -lm
```

Or with explicit C99 standard:
```bash
gcc -std=c99 matops.c -o matops -lm -Wall
```

**Note:** The `-lm` flag is required to link the math library for `sqrt()` function.

### For Windows Users
Replace `system("clear")` with `system("cls")` in the source code before compiling.

Find and replace in these locations:
```c
// Around line 581
system("cls");  // Instead of system("clear")
```

---

## 🚀 Usage

### Running the Program
```bash
./matops
```

### First Run
On first run, the program will:
1. Create `password.txt` if it doesn't exist
2. Set default password to `12345`
3. Display the login screen

### Login
- **Default Password:** `12345`
- **Attempts Allowed:** 5
- **Password Storage:** Saved in `password.txt`
- Password can be changed via System Settings (Option 8 → 6)

### Main Menu Navigation
```
------------------
WELCOME TO MATOPS
------------------

CHOOSE OPERATIONS:
1. MATRIX MULTIPLICATION
2. DETERMINANT (upto 3 * 3 matrix)
3. INVERSE
4. CHARACTERSTIC EQUATION
5. EIGEN VALUE
6. EIGEN VECTOR
7. TRANSPOSE OF A MATRIX
8. SYSTEM SETTINGS
9. CLEAR SCREEN
0. EXIT
```

---

## 📚 Examples

### Example 1: Matrix Multiplication (2×3 × 3×2)

```
ENTER YOUR CHOICE: 1

ENTER THE NUMBER OF ROWS OF MATRIX A:-
2

ENTER THE NUMBER OF COLUMN OF MATRIX A:-
3

ENTER THE NUMBER OF ROWS IN MATRIX B:-
3

ENTER THE NUMBER OF COLUMN IN MATRIX B:-
2

ENTER THE ELEMENTS OF MATRIX A:-
1 2 3
4 5 6

ENTER THE ELEMENTS OF MATRIX B:-
7 8
9 10
11 12

------------------------------------------------------------
THE RESULT OF MULTIPLICATION OF MATRIX A AND MATRIX B IS:-
58      64
139     154
------------------------------------------------------------
```

**Calculation:**
```
A × B = [1×7 + 2×9 + 3×11    1×8 + 2×10 + 3×12]
        [4×7 + 5×9 + 6×11    4×8 + 5×10 + 6×12]
      = [58   64]
        [139  154]
```

### Example 2: Determinant (3×3)

```
ENTER YOUR CHOICE: 2

ENTER THE NUMBER OF ROWS OF MATRIX A:-
3

ENTER THE NUMBER OF COLUMN OF MATRIX A:-
3

ENTER THE ELEMENTS OF MAT A:
1 2 3
0 1 4
5 6 0

------------------------------
DETERMINANT OF MATRIX A IS :1
------------------------------
```

**Calculation:**
```
det(A) = 1(1×0 - 4×6) - 2(0×0 - 4×5) + 3(0×6 - 1×5)
       = 1(-24) - 2(-20) + 3(-5)
       = -24 + 40 - 15
       = 1
```

### Example 3: Matrix Inverse (2×2)

```
ENTER YOUR CHOICE: 3

ENTER THE NUMBER OF ROWS OF MATRIX A:-
2

ENTER THE NUMBER OF COLUMN OF MATRIX A:-
2

ENTER ELEMENTS OF MATRIX A:
4 7
2 6

---------------------------
INVERSE OF MATRIX A IS : 
0.60    -0.70
-0.20    0.40
---------------------------
```

**Calculation:**
```
det(A) = 4×6 - 7×2 = 24 - 14 = 10

A⁻¹ = (1/10) × [ 6  -7]  = [0.60  -0.70]
               [-2   4]    [-0.20  0.40]
```

### Example 4: Characteristic Equation (2×2)

```
ENTER YOUR CHOICE: 4

ENTER THE NUMBER OF ROWS OF MATRIX A:-
2

ENTER THE NUMBER OF COLUMN OF MATRIX A:-
2

ENTER ELEMENTS OF MATRIX A:
3 1
1 3

--------------------------------------
CHARATERSTIC EQUATION OF MATRIX A IS:
λ² - 6λ + 8
---------------------------------------
```

**Explanation:**
```
Trace = 3 + 3 = 6
det(A) = 3×3 - 1×1 = 8

Characteristic equation: λ² - (trace)λ + det = λ² - 6λ + 8
```

### Example 5: Eigenvalues (2×2)

```
ENTER YOUR CHOICE: 5

ENTER THE NUMBER OF ROWS OF MATRIX A:-
2

ENTER THE NUMBER OF COLUMN OF MATRIX A:-
2

ENTER ELEMENTS OF MATRIX A:
3 1
1 3

-------------------------------------
EIGEN VALUE OF MATRIX A IS : 4.000000 and 2.000000
-------------------------------------
```

**Calculation:**
```
Characteristic equation: λ² - 6λ + 8 = 0

Using quadratic formula:
λ = (6 ± √(36 - 32))/2 = (6 ± 2)/2

λ₁ = 4, λ₂ = 2
```

### Example 6: Transpose (2×3)

```
ENTER YOUR CHOICE: 7

ENTER THE NUMBER OF ROWS OF MATRIX A:-
2

ENTER THE NUMBER OF COLUMN OF MATRIX A:-
3

ENTER ELEMENTS OF MATRIX A:
1 2 3
4 5 6

------------------------------------
THE TRANSPOSE OF THE MATRIX A IS:
1       4
2       5
3       6
------------------------------------
```

---

## ⚙️ System Settings

Access via main menu option 8:

```
---------------
SYSTEM SETTINGS
---------------
1. VERSION NUMBER
2. AUTHOR
3. MAINTAINER
4. RECENT UPDATE DATE
5. SUPPORTED MATRIX LIMITS
6. CHANGE PASSWORD
7. CLEAR SCREEN
8. RETURN TO PREVIOUS MENU
9. LOG OUT
```

### System Settings Options

#### 1. Version Number
Displays current version: **4.0.0**

#### 2. Author
Shows author information: **ANANT RAJPUT**

#### 3. Maintainer
Displays maintainer: **ANANT RAJPUT**

#### 4. Recent Update Date
Last updated: **25 . DECEMBER . 2025**

#### 5. Supported Matrix Limits
```
------------------------------------------------
SUPPORTED MATRIX LIMITS
------------------------------------------------
• Multiplication : Any size (A[r×c], B[c×k])
• Determinant    : Up to 3 × 3
• Inverse        : 1 × 1, 2 × 2, 3 × 3
• Eigen Values   : 2 × 2 , 3 × 3
• Eigen Vectors  : 2 × 2 only
• Transpose      : Any size
------------------------------------------------
```

#### 6. Change Password
**Security-Enhanced Password Change Process:**

- Requires current password verification (3 attempts)
- New password must be entered twice for confirmation
- Password saved to `password.txt` automatically
- Automatic **FORCEFUL EVICTION** after 3 failed verification attempts
- Security feature to prevent unauthorized password changes

**Password Change Flow:**
1. Enter current password for verification
2. If correct, enter new password
3. Confirm new password (must match)
4. Success message displayed
5. Password saved to file
6. New password takes effect immediately

**Failed Attempt Handling:**
- **Attempts 1-2:** Warning with remaining attempts displayed
  ```
  Password is INCORRECT, TRY AGAIN (Attempts left = X)
  ```
- **Attempt 3:** System logs you out for security
  ```
  Password is INCORRECT, NO MORE TRIES LEFT
  Commencing FORCEFUL EVICTION due to security reasons.....LOADING.....
  ```

**Password Mismatch:**
- If new password and confirmation don't match:
  ```
  Both input password are different. TRY AGAIN
  ```
- 3 attempts allowed for password confirmation

#### 7. Clear Screen
Clears the terminal for better visibility using `system("clear")`

#### 8. Return to Previous Menu
Returns to main operations menu without logging out

#### 9. Log Out
```
Logged Out of the System Successfully.
```
Exits to login screen while keeping program running

---

## 🛡️ Error Handling

The program validates and handles various error conditions:

### Input Validation Errors

| Error Type | Validation | User Feedback |
|------------|------------|---------------|
| **Zero Dimensions** | Rejects matrices with 0 rows/columns | "ROWS AND COLUMNS MUST BE GREATER THAN ZERO." |
| **Non-Square Matrix** | Validates square requirement for det/inverse/eigen/char.eq. | Operation-specific error messages |
| **Incompatible Multiplication** | Checks c₁ = r₂ for A×B | "SORRY! THE MULTIPLICATION OF THE MATRIX IS NOT POSSIBLE." |
| **Singular Matrix** | Detects det = 0 for inverse calculation | "INVERSE DOES NOT EXIST" |
| **Unsupported Size** | Clear messages for operations beyond limits | "ONLY 2X2 AND 3X3 MATRIX SUPPORTED", etc. |

### Authentication Errors

| Error Type | Attempts Allowed | User Feedback |
|------------|------------------|---------------|
| **Login Failure** | 5 attempts | "INCORRECT PASSWORD. NUMBER OF ATTEMPST LEFT = X" |
| **Final Login Attempt** | After 5th failure | "INCORRECT PASSWORD. NO MORE ATTEMPTS LEFT" → Program exits |
| **Password Change Verification** | 3 attempts | "Password is INCORRECT, TRY AGAIN (Attempts left = X)" |
| **Password Change Final Failure** | After 3rd failure | "FORCEFUL EVICTION" → Logged out |

### Menu Errors

| Error Type | Valid Range | User Feedback |
|------------|-------------|---------------|
| **Invalid Main Menu Choice** | 0-9 | "INVALID RESPOSE (X). VALID RESPONSE = 0 - 9" |
| **Invalid Settings Choice** | 1-9 | "Invalid Response Detected (X). Valid response = (1 - 6)" |

### Operation-Specific Errors

#### Determinant Errors
```
--------------------------
DETERMINANT DOES NOT EXIST
--------------------------
```
Shown when matrix is not square.

#### Inverse Errors
```
----------------------
INVERSE DOES NOT EXIST
----------------------
```
Shown when:
- Matrix is not square
- Determinant is zero (singular matrix)

```
--------------------------------------
ONLY 1X1, 2X2 AND 3X3 MATRIX SUPPORTED
--------------------------------------
```
Shown for matrices larger than 3×3.

#### Characteristic Equation Errors
```
------------------------------------------------------
characteric equation is only defined for square matrix.
------------------------------------------------------
```

```
------------------------------------
only 2x2 and 3x3 matrix is supported
------------------------------------
```

#### Eigenvalue/Eigenvector Errors
```
-------------------------------------------------
EIGEN VALUES ARE ONLY DEFINED FOR A SQUARE MATRIX
-------------------------------------------------
```

```
-----------------------------
ONLY 2x2 MARRIX ARE SUPPORTED
-----------------------------
```

---

## ⚠️ Limitations

### Matrix Size Constraints

| Operation | Supported Sizes | Algorithm | Note |
|-----------|----------------|-----------|------|
| Multiplication | Any (memory limited) | Standard algorithm | Limited by stack size |
| Determinant | 1×1, 2×2, 3×3 | Cofactor expansion | Analytical formulas |
| Inverse | 1×1, 2×2, 3×3 | Adjugate method | Uses determinant |
| Characteristic Equation | 2×2, 3×3 | Analytical formulas | Trace & determinant based |
| Eigenvalues | 2×2 only | Quadratic formula | Real eigenvalues only |
| Eigenvectors | 2×2 only | Simplified formula | Based on eigenvalues |
| Transpose | Any | Direct computation | No limitation |

### Technical Limitations

- **Complex Numbers:** No support for complex eigenvalues/eigenvectors
  - Complex eigenvalues display as `nan` (Not a Number)
  - No user-friendly warning provided
  
- **Data Types:**
  - Matrix multiplication, determinant, characteristic equation: **Integer input/output**
  - Inverse: **Float input/output** (2 decimal precision)
  - Eigenvalues/eigenvectors: **Integer input**, **float output**

- **Precision:** Standard floating-point limitations
  - Uses `float` for inverse calculation
  - Uses `double` internally for `sqrt()` calculations
  - Output limited to 2 decimal places

- **Memory:** 
  - VLA (Variable Length Array) size limited by available stack memory
  - Large matrices may cause stack overflow
  - No dynamic heap allocation used

- **Platform:** 
  - `system("clear")` command is Unix/Linux specific
  - Windows requires modification to `system("cls")`

- **Password Security:**
  - Password stored in plain text in `password.txt`
  - Password stored as integer (numeric only)
  - File permissions not explicitly set
  - No encryption applied

- **File Handling:**
  - If `password.txt` is corrupted, defaults to 12345
  - No backup password mechanism
  - File must be writable in current directory

### Known Issues

1. **Eigenvector Formatting:** Uses `%.2d` instead of `%.2f` for float values (line in code shows formatting inconsistency)

2. **Complex Eigenvalues:** When a 2×2 matrix has complex eigenvalues (discriminant < 0), `sqrt()` of negative number produces `nan` without explanation

3. **Input Validation:** No validation for non-numeric input
   - Entering letters causes undefined behavior
   - Program may crash or produce garbage values

4. **Typos in Output:**
   - "ATTEMPST" instead of "ATTEMPTS" (line 695)
   - "characteric" instead of "characteristic" (line 406)
   - "MARRIX" instead of "MATRIX" (line 521, 550)

5. **Inconsistent Validation Messages:** Settings menu shows "Valid response = (1 - 6)" but actually accepts 1-9

6. **Password File Security:** Plain text password storage is a security risk

7. **No Confirmation:** Exit (option 0) doesn't ask for confirmation

---

## 🔮 Future Enhancements

### High Priority

- [ ] **Complex Number Support**
  - Handle complex eigenvalues and eigenvectors
  - Display in a+bi format
  - Proper mathematical representation

- [ ] **Larger Matrix Support**
  - Extend determinant calculation to n×n matrices
  - Implement LU decomposition for inverse
  - QR algorithm for eigenvalues of larger matrices

- [ ] **Input Validation**
  - Handle non-numeric input gracefully
  - Validate input ranges
  - Add input sanitization

- [ ] **Cross-Platform Compatibility**
  - Automatic detection of OS
  - Use appropriate clear screen command
  - Portable file paths

- [ ] **Enhanced Security**
  - Encrypt password in file
  - Use secure password hashing
  - Add password strength requirements
  - Implement session timeouts

### Medium Priority

- [ ] **Additional Operations**
  - Matrix addition and subtraction
  - Scalar multiplication and division
  - Matrix exponentiation
  - Rank calculation
  - RREF (Reduced Row Echelon Form)
  - Trace as separate operation
  - Norm calculations (L1, L2, infinity)

- [ ] **Gaussian Elimination**
  - Solve systems of linear equations
  - General solution finding
  - Pivoting strategies

- [ ] **Advanced Decompositions**
  - LU decomposition
  - QR decomposition
  - Cholesky decomposition
  - SVD (Singular Value Decomposition)

- [ ] **Better Eigenvector Display**
  - Normalized eigenvectors
  - Proper formatting
  - Handle zero eigenvalues correctly

### Low Priority

- [ ] **File I/O**
  - Import matrices from CSV/text files
  - Export results to files
  - Save calculation history
  - JSON format support

- [ ] **Batch Processing**
  - Process multiple matrices
  - Script mode for automation
  - Command-line arguments

- [ ] **GUI Version**
  - GTK+ interface for Linux
  - Qt for cross-platform
  - Web-based interface

- [ ] **Advanced Features**
  - Matrix calculus operations
  - Symbolic computation support
  - Step-by-step solution display
  - Matrix visualization (ASCII art)

### Code Quality Improvements

- [ ] **Refactoring**
  - Separate functions for each operation
  - Modular code structure
  - Header files for organization
  - Reduce code duplication

- [ ] **Error Handling**
  - Implement error codes
  - Consistent error messages
  - Logging system
  - Better exception handling

- [ ] **Memory Management**
  - Move to heap allocation for large matrices
  - Implement proper cleanup
  - Memory leak detection
  - Buffer overflow protection

- [ ] **Testing**
  - Unit tests for each operation
  - Integration tests
  - Edge case coverage
  - Automated testing framework

- [ ] **Documentation**
  - Inline code comments
  - API documentation
  - Developer guide
  - Mathematical explanations

---

## 🤝 Contributing

Contributions are welcome! Here's how you can help improve MATOPS:

### How to Contribute

1. **Fork** the repository
   ```bash
   git clone https://github.com/yourusername/matops.git
   ```

2. **Create** a feature branch
   ```bash
   git checkout -b feature/amazing-feature
   ```

3. **Make** your changes
   - Write clean, readable code
   - Follow existing code style
   - Add comments for complex logic

4. **Test** thoroughly
   - Test with various inputs
   - Check edge cases
   - Verify no memory leaks

5. **Commit** your changes
   ```bash
   git commit -m 'Add amazing feature: detailed description'
   ```

6. **Push** to the branch
   ```bash
   git push origin feature/amazing-feature
   ```

7. **Open** a Pull Request
   - Provide clear description
   - Reference any related issues
   - Include screenshots if applicable

### Contribution Guidelines

#### Code Style
- **Indentation:** 4 spaces (no tabs)
- **Braces:** K&R style
  ```c
  if (condition) {
      // code
  }
  ```
- **Naming:**
  - Variables: `snake_case`
  - Functions: `snake_case`
  - Constants: `UPPER_CASE`
- **Comments:** Clear and concise
  ```c
  // Calculate determinant using cofactor expansion
  detA = arr1[0][0] * (arr1[1][1] * arr1[2][2] - arr1[1][2] * arr1[2][1])
       - arr1[0][1] * (arr1[1][0] * arr1[2][2] - arr1[1][2] * arr1[2][0])
       + arr1[0][2] * (arr1[1][0] * arr1[2][1] - arr1[1][1] * arr1[2][0]);
  ```

#### What to Contribute

**Bug Fixes:**
- Fix typos in output messages
- Correct calculation errors
- Fix memory issues
- Improve error handling

**New Features:**
- Add new matrix operations
- Implement larger matrix support
- Add complex number handling
- Create file I/O functionality

**Documentation:**
- Improve README
- Add code comments
- Create tutorials
- Write examples

**Testing:**
- Write test cases
- Report bugs
- Suggest improvements
- Validate calculations

### Testing Checklist

Before submitting a pull request, ensure:

- [ ] Code compiles without warnings
  ```bash
  gcc -std=c99 -Wall -Wextra matops.c -o matops -lm
  ```
- [ ] All operations work correctly
- [ ] Edge cases handled (zero matrices, singular matrices, etc.)
- [ ] No memory leaks (test with valgrind if possible)
  ```bash
  valgrind --leak-check=full ./matops
  ```
- [ ] Error messages are clear
- [ ] Documentation updated
- [ ] Code follows style guidelines
- [ ] Backward compatibility maintained

### Types of Contributions Needed

| Priority | Type | Examples |
|----------|------|----------|
| 🔴 High | Bug Fixes | Eigenvector formatting, typos, input validation |
| 🟡 Medium | Features | New operations, larger matrix support |
| 🟢 Low | Enhancement | GUI, file I/O, optimization |
| 🔵 Documentation | Docs | Comments, tutorials, examples |

### Development Setup

```bash
# Clone the repository
git clone https://github.com/yourusername/matops.git
cd matops

# Create development branch
git checkout -b dev

# Compile with all warnings
gcc -std=c99 -Wall -Wextra -Wpedantic matops.c -o matops -lm

# Run the program
./matops
```

### Code Review Process

1. **Automated Checks:** Basic compilation and style checks
2. **Manual Review:** Code quality and functionality review
3. **Testing:** Verification of changes
4. **Feedback:** Suggestions for improvement
5. **Approval:** Merge into main branch

---

## 📄 License

This project is licensed under the **MIT License**.

### MIT License

```
MIT License

Copyright (c) 2025 Anant Rajput

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```

### What This Means

✅ **You CAN:**
- Use the software for commercial purposes
- Modify the software
- Distribute the software
- Use the software privately
- Sublicense the software

❌ **You CANNOT:**
- Hold the author liable
- Expect warranty or guarantee

📋 **You MUST:**
- Include the license and copyright notice
- State changes made to the code

---

## 📞 Contact

**Author & Maintainer:** Anant Rajput

### Get in Touch

- **GitHub Issues:** [Report bugs or request features](https://github.com/yourusername/matops/issues)
- **Pull Requests:** [Contribute code](https://github.com/yourusername/matops/pulls)
- **Email:** your.email@example.com
- **LinkedIn:** [Your LinkedIn Profile](https://linkedin.com/in/yourprofile)

### Support

If you find this project helpful:
- ⭐ Star the repository
- 🐛 Report bugs
- 💡 Suggest features
- 🤝 Contribute code
- 📢 Share with others

---

## 🙏 Acknowledgments

- **Mathematical Foundation:** Standard linear algebra algorithms and formulations
- **Educational Purpose:** Built to help students understand matrix operations
- **Open Source Community:** Thanks to all contributors and users for feedback
- **C Programming:** Inspired by the simplicity and power of C language
- **Learning Resource:** Designed as both a tool and a learning reference

### Special Thanks To:
- Students who provided feedback and feature requests
- Contributors who helped improve the code
- The open-source community for inspiration
- Mathematics educators for validation of algorithms

---

## 📊 Project Statistics

| Metric | Value |
|--------|-------|
| **Current Version** | 4.0.0 |
| **Development Status** | Active |
| **Last Updated** | December 25, 2025 |
| **Lines of Code** | ~700 |
| **Language** | C (C99 standard) |
| **License** | MIT |
| **Stability** | Stable (Production Ready) |
| **Platforms** | Linux/Unix (Windows compatible with modifications) |

### Version History

| Version | Date | Changes |
|---------|------|---------|
| **4.0.0** | Dec 25, 2025 | Current stable release - Enhanced security features, improved error handling |
| **3.2.5** | Dec 25, 2025 | Bug fixes and performance improvements |
| **3.2.4** | Dec 24, 2025 | Minor updates and stability improvements |
| **2.2.0** | Dec 22, 2025 | Feature additions and code refactoring |
| Earlier | - | Previous versions (not documented) |

---

## 🔐 Security

### Security Considerations

⚠️ **Important Security Notes:**

1. **Password Storage:**
   - Passwords stored in plain text in `password.txt`
   - **Not suitable for sensitive environments**
   - For educational/personal use only

2. **File Permissions:**
   - `password.txt` created with default permissions
   - Recommend setting `chmod 600 password.txt` on Unix systems

3. **Input Validation:**
   - Limited validation of user input
   - Malicious input may cause crashes
   - Do not expose to untrusted users

4. **Buffer Security:**
   - VLA usage may cause stack overflow
   - No bounds checking on very large matrices

### Security Best Practices

If using in any production or shared environment:

1. **Change Default Password Immediately**
   ```
   Default: 12345 → Change via System Settings (8 → 6)
   ```

2. **Secure the Password File**
   ```bash
   chmod 600 password.txt  # Unix/Linux
   ```

3. **Run with Limited Privileges**
   - Don't run as root/administrator
   - Use dedicated user account

4. **Monitor for Unusual Behavior**
   - Check for unexpected file access
   - Monitor program crashes

### Reporting Security Issues

If you discover a security vulnerability:
1. **DO NOT** open a public issue
2. Email directly to: security@example.com
3. Include detailed description
4. Provide steps to reproduce
5. Allow time for patch before disclosure

---

## ⚠️ Important Notes

### ⚠️ Security Warning
**The default password is `12345`.** For any shared or production environment, change the password immediately via System Settings (Option 8 → 6). The password is stored in plain text in `password.txt` and is not encrypted.

### 💻 Platform Compatibility
**This program uses `system("clear")` which is Unix/Linux specific.** 

**Windows users must:**
1. Replace `system("clear")` with `system("cls")`
2. Recompile the program

**OR use:**
```c
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
```

### 💾 Memory Limitations
**Large matrices may cause stack overflow** due to VLA usage. 

**Recommendations:**
- Keep matrix dimensions reasonable (<100×100)
- For very large matrices, consider implementing heap allocation
- Monitor system memory during operations

### 📁 File Requirements
**The program needs write access** to create and modify `password.txt` in the current directory.

**Ensure:**
- Current directory is writable
