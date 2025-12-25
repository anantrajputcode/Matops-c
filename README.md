# MATOPS - Matrix Operations Calculator

A comprehensive command-line matrix operations calculator written in C, featuring password protection, multiple matrix operations, and an intuitive menu-driven interface.

**Author:** Anant Rajput  
**Version:** 3.2.5  
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

- **🔐 Password Protected:** Secure login system with 5-attempt limit (default: `12345`)
- **📊 Seven Matrix Operations:** Complete suite of linear algebra operations
- **✅ Input Validation:** Comprehensive dimension and compatibility checks
- **🎯 User-Friendly Interface:** Clear, menu-driven navigation
- **⚙️ System Settings:** Password management and program information
- **🧹 Screen Management:** Clear screen functionality for better organization
- **💾 Memory Efficient:** Dynamic memory allocation using VLAs
- **🔄 Session Persistence:** Continue operations without restarting

---

## 🔢 Operations Supported

### 1. Matrix Multiplication
- Multiplies two matrices A[r₁×c₁] and B[r₂×c₂]
- Validates compatibility (c₁ must equal r₂)
- Supports any valid matrix dimensions
- **Output:** Result matrix of size r₁×c₂

### 2. Determinant Calculation
- Computes determinants using cofactor expansion
- **Supported sizes:** 1×1, 2×2, 3×3
- Validates square matrix requirement
- **Output:** Integer determinant value

### 3. Matrix Inverse
- Calculates inverse using adjugate method
- **Supported sizes:** 1×1, 2×2, 3×3
- Checks for singular matrices (det = 0)
- **Output:** Floating-point inverse (2 decimal places)

### 4. Characteristic Equation
- Derives characteristic polynomial
- **Supported sizes:** 2×2, 3×3
- **Output format:**
  - 2×2: `λ² - (trace)λ + det`
  - 3×3: `λ³ - (trace)λ² + (sum of minors)λ - det`

### 5. Eigenvalues
- Calculates eigenvalues using quadratic formula
- **Supported sizes:** 2×2 only
- Handles real eigenvalues
- **Output:** Both eigenvalues (floating-point)

### 6. Eigenvectors
- Computes eigenvectors corresponding to eigenvalues
- **Supported sizes:** 2×2 only
- **Output:** Two eigenvectors in column form

### 7. Transpose
- Swaps rows and columns
- **Supported sizes:** Any dimensions
- **Output:** Transposed matrix

---

## 🛠️ Prerequisites

- **C Compiler:** GCC 4.8+ or any C99-compatible compiler
- **Operating System:** Linux/Unix (uses `system("clear")`)
- **Math Library:** Standard C math library (`-lm` flag required)
- **Knowledge:** Basic understanding of linear algebra

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
gcc -std=c99 matops.c -o matops -lm
```

**Note:** The `-lm` flag is required to link the math library for `sqrt()` function.

### For Windows Users
Replace `system("clear")` with `system("cls")` in the source code before compiling:
- Line 48: `system("cls")`
- Line 562: `system("cls")`
- Line 579: `system("cls")`

---

## 🚀 Usage

### Running the Program
```bash
./matops
```

### Login
- **Default Password:** `12345`
- **Attempts Allowed:** 5
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

### Example 4: Eigenvalues (2×2)

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

### Example 5: Transpose (2×3)

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
Displays current version: **3.2.5**

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
- Requires current password verification (3 attempts)
- New password must be entered twice for confirmation
- Automatic **FORCEFUL EVICTION** after 3 failed verification attempts
- Security feature to prevent unauthorized password changes

**Password Change Flow:**
1. Enter current password
2. If correct, enter new password
3. Confirm new password
4. Success message displayed
5. New password takes effect immediately

**Failed Attempt Handling:**
- Attempts 1-2: Warning with remaining attempts
- Attempt 3: System logs you out for security

#### 7. Clear Screen
Clears the terminal for better visibility

#### 8. Return to Previous Menu
Goes back to main operations menu

#### 9. Log Out
Exits to login screen

---

## 🛡️ Error Handling

The program validates and handles:

| Error Type | Validation | User Feedback |
|------------|------------|---------------|
| **Zero Dimensions** | Rejects matrices with 0 rows/columns | "ROWS AND COLUMNS MUST BE GREATER THAN ZERO." |
| **Non-Square Matrix** | Validates square requirement for det/inverse/eigen | Operation-specific error messages |
| **Incompatible Multiplication** | Checks c₁ = r₂ for A×B | "SORRY! THE MULTIPLICATION OF THE MATRIX IS NOT POSSIBLE." |
| **Singular Matrix** | Detects det = 0 for inverse calculation | "INVERSE DOES NOT EXIST" |
| **Unsupported Size** | Clear messages for operations beyond limits | Specific size limit messages |
| **Password Failures** | Locks system after 5 failed login attempts | Attempt counter displayed |
| **Invalid Menu Input** | Prompts for valid range (0-9) | "INVALID RESPOSE (X). VALID RESPONSE = 0 - 9" |
| **Password Change Security** | 3-attempt limit for password verification | "FORCEFUL EVICTION" on failure |

---

## ⚠️ Limitations

### Matrix Size Constraints
| Operation | Supported Sizes | Note |
|-----------|----------------|------|
| Multiplication | Any (memory limited) | Limited by stack size |
| Determinant | 1×1, 2×2, 3×3 | Cofactor expansion |
| Inverse | 1×1, 2×2, 3×3 | Adjugate method |
| Characteristic Equation | 2×2, 3×3 | Analytical formulas |
| Eigenvalues | 2×2 | Quadratic formula |
| Eigenvectors | 2×2 | Based on eigenvalues |
| Transpose | Any | No limitation |

### Technical Limitations
- **Complex Numbers:** No support for complex eigenvalues/eigenvectors (displays as NaN)
- **Precision:** Standard floating-point limitations (double precision)
- **Memory:** VLA size limited by available stack memory
- **Platform:** `system("clear")` command is Unix/Linux specific
- **Password:** Stored in plain text in memory (security consideration)
- **Integer Input:** Matrices use integer values (except inverse uses float)
- **Eigenvalue Algorithm:** Only works for 2×2 matrices with real eigenvalues

### Known Issues
- Eigenvector display format uses `%.2d` for integer formatting (should be reviewed)
- Complex eigenvalues appear as NaN without user-friendly explanation
- No input validation for non-numeric entries

---

## 🔮 Future Enhancements

Potential improvements for future versions:

### High Priority
- [ ] Support for larger matrices (4×4, 5×5, n×n)
- [ ] Complex number support for eigenvalues/eigenvectors
- [ ] Better eigenvector calculation and display
- [ ] Input validation for non-numeric entries
- [ ] Cross-platform compatibility (Windows/Mac/Linux)

### Medium Priority
- [ ] Matrix addition and subtraction
- [ ] Gaussian elimination for general systems
- [ ] LU decomposition implementation
- [ ] QR algorithm for larger eigenvalue problems
- [ ] Matrix rank calculation
- [ ] RREF (Reduced Row Echelon Form)

### Low Priority
- [ ] File I/O for matrix data (CSV/JSON)
- [ ] Encrypted password storage
- [ ] SVD (Singular Value Decomposition)
- [ ] GUI version using GTK/Qt
- [ ] Batch processing mode
- [ ] Matrix exponentiation
- [ ] Norm calculations (L1, L2, infinity)
- [ ] Trace calculation as separate operation
- [ ] Matrix scalar operations (multiply, divide, add)

### Code Quality
- [ ] Refactor code into separate functions
- [ ] Add comprehensive error codes
- [ ] Improve memory management
- [ ] Add unit tests
- [ ] Better documentation in code
- [ ] Reduce code duplication

---

## 🤝 Contributing

Contributions are welcome! Here's how you can help:

### How to Contribute

1. **Fork** the repository
2. **Create** a feature branch
   ```bash
   git checkout -b feature/amazing-feature
   ```
3. **Commit** your changes
   ```bash
   git commit -m 'Add amazing feature'
   ```
4. **Push** to the branch
   ```bash
   git push origin feature/amazing-feature
   ```
5. **Open** a Pull Request

### Contribution Guidelines
- Follow existing code style and formatting
- Add comments for complex logic
- Test thoroughly with various inputs including edge cases
- Update documentation for new features
- Handle edge cases and errors appropriately
- Ensure backward compatibility where possible
- Add examples for new features

### Code Style
- Use descriptive variable names for clarity
- Maintain consistent indentation (4 spaces)
- Add comments for non-obvious logic
- Keep functions focused and modular
- Follow C99 standard conventions

### Testing Checklist
- [ ] Test with valid inputs
- [ ] Test with invalid inputs (negative numbers, zero, etc.)
- [ ] Test boundary conditions
- [ ] Test memory leaks (if applicable)
- [ ] Test on multiple platforms (if possible)

---

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

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

---

## 📞 Contact

**Author & Maintainer:** Anant Rajput

For questions, bug reports, or feature requests:
- Open an issue in the repository
- Submit a pull request
- Contact via email (add your email here)
- Star the repository if you find it useful! ⭐

---

## 🙏 Acknowledgments

- Linear algebra algorithms based on standard mathematical formulations
- Inspired by the need for a simple, accessible matrix calculator for students
- Built with educational purposes in mind
- Thanks to all contributors and users for feedback and suggestions

---

## 📊 Project Status

**Current Version:** 3.2.5  
**Status:** Active Development  
**Last Updated:** December 25, 2025  
**Stability:** Stable (Production Ready)

### Version History
- **3.2.5** (Dec 25, 2025) - Current stable release
- **3.2.4** (Dec 24, 2025) - Previous release
- Earlier versions not documented

---

## ⚠️ Important Notes

### Security
**⚠️ Security Warning:** The default password is `12345`. For production or shared environments, change the password immediately via System Settings or modify the source code.

### Platform Compatibility
**💻 Platform Note:** This program uses `system("clear")` which is Unix/Linux specific. Windows users must replace it with `system("cls")` before compiling.

### Memory Usage
**💾 Memory Note:** Large matrices may cause stack overflow due to VLA usage. For very large matrices (>100×100), consider implementing heap allocation.

---

## 💡 Tips & Tricks

- **Quick Clear:** Use option 9 in the main menu to clear the screen for better visibility
- **Password Safety:** Change default password on first use
- **Session Continuity:** After operations, you stay logged in—no need to re-enter password
- **Matrix Input:** Enter matrix elements row by row, separated by spaces
- **Error Messages:** Read error messages carefully—they indicate exactly what went wrong
- **System Settings:** Explore option 8 to see all available settings and limits

---

## 🐛 Bug Reports

If you encounter any bugs, please report them by:
1. Opening an issue on GitHub
2. Providing detailed steps to reproduce
3. Including expected vs actual behavior
4. Sharing your system information (OS, compiler version)
5. Attaching any relevant error messages

---

**Made with ❤️ for Linear Algebra Students**

*Happy Matrix Computing!* 🎓✨