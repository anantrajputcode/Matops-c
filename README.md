# MATOPS - Matrix Operations Calculator

A comprehensive command-line matrix operations calculator written in C, featuring password protection, multiple matrix operations, and an intuitive menu-driven interface.

**Author:** Anant Rajput  
**Version:** 3.2.4  
**Last Updated:** December 24, 2025

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

- **🔐 Password Protected:** Secure login system with 5-attempt limit (default: `1`)
- **📊 Seven Matrix Operations:** Complete suite of linear algebra operations
- **✅ Input Validation:** Comprehensive dimension and compatibility checks
- **🎯 User-Friendly Interface:** Clear, menu-driven navigation
- **⚙️ System Settings:** Password management and program information
- **🧹 Screen Management:** Clear screen functionality for better organization
- **💾 Memory Efficient:** Dynamic memory allocation using VLAs

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
- **Output:** Both eigenvalues (may show complex as NaN)

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
- **Math Library:** Standard C math library
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
Replace `system("clear")` with `system("cls")` in the source code before compiling.

---

## 🚀 Usage

### Running the Program
```bash
./matops
```

### Login
- **Default Password:** `1`
- **Attempts Allowed:** 5
- Password can be changed via System Settings

### Main Menu Navigation
```
1. MATRIX MULTIPLICATION
2. DETERMINANT (up to 3×3 matrix)
3. INVERSE
4. CHARACTERISTIC EQUATION
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

ENTER THE NUMBER OF ROWS OF MATRIX A: 2
ENTER THE NUMBER OF COLUMN OF MATRIX A: 3
ENTER THE NUMBER OF ROWS IN MATRIX B: 3
ENTER THE NUMBER OF COLUMN IN MATRIX B: 2

ENTER THE ELEMENTS OF MATRIX A:
1 2 3
4 5 6

ENTER THE ELEMENTS OF MATRIX B:
7 8
9 10
11 12

THE RESULT OF MULTIPLICATION OF MATRIX A AND MATRIX B IS:
58      64
139     154
```

### Example 2: Determinant (3×3)

```
ENTER YOUR CHOICE: 2

ENTER THE NUMBER OF ROWS OF MATRIX A: 3
ENTER THE NUMBER OF COLUMN OF MATRIX A: 3

ENTER THE ELEMENTS OF MAT A:
1 2 3
0 1 4
5 6 0

DETERMINANT OF MATRIX A IS: 1
```

### Example 3: Matrix Inverse (2×2)

```
ENTER YOUR CHOICE: 3

ENTER THE NUMBER OF ROWS OF MATRIX A: 2
ENTER THE NUMBER OF COLUMN OF MATRIX A: 2

ENTER ELEMENTS OF MATRIX A:
4 7
2 6

INVERSE OF MATRIX A IS:
0.60    -0.70
-0.20    0.40
```

### Example 4: Transpose (2×3)

```
ENTER YOUR CHOICE: 7

ENTER THE NUMBER OF ROWS OF MATRIX A: 2
ENTER THE NUMBER OF COLUMN OF MATRIX A: 3

ENTER ELEMENTS OF MATRIX A:
1 2 3
4 5 6

THE TRANSPOSE OF THE MATRIX A IS:
1       4
2       5
3       6
```

---

## ⚙️ System Settings

Access via main menu option 8:

```
SYSTEM SETTINGS
---------------
1. VERSION NUMBER       → View current version (3.2.4)
2. AUTHOR              → View author information
3. MAINTAINER          → View maintainer details
4. RECENT UPDATE DATE  → Last update: December 24, 2025
5. SUPPORTED MATRIX LIMITS → View operation limitations
6. CHANGE PASSWORD     → Modify login password (3 attempts)
7. CLEAR SCREEN        → Clear terminal display
8. RETURN TO PREVIOUS MENU
9. LOG OUT             → Exit to login screen
```

### Supported Matrix Limits
- **Multiplication:** Any size (A[r×c], B[c×k])
- **Determinant:** Up to 3×3
- **Inverse:** 1×1, 2×2, 3×3
- **Eigen Values:** 2×2, 3×3
- **Eigen Vectors:** 2×2 only
- **Transpose:** Any size

### Password Change Feature
- Requires current password verification (3 attempts)
- New password must be entered twice for confirmation
- Automatic logout after 3 failed verification attempts

---

## 🛡️ Error Handling

The program validates and handles:

| Error Type | Validation |
|------------|------------|
| **Zero Dimensions** | Rejects matrices with 0 rows/columns |
| **Non-Square Matrix** | Validates square requirement for det/inverse/eigen operations |
| **Incompatible Multiplication** | Checks c₁ = r₂ for A×B |
| **Singular Matrix** | Detects det = 0 for inverse calculation |
| **Unsupported Size** | Clear messages for operations beyond limits |
| **Password Failures** | Locks system after 5 failed attempts |
| **Invalid Menu Input** | Prompts for valid range (0-9 or 1-9) |

---

## ⚠️ Limitations

### Matrix Size Constraints
| Operation | Supported Sizes |
|-----------|----------------|
| Multiplication | Any (limited by stack memory) |
| Determinant | 1×1, 2×2, 3×3 |
| Inverse | 1×1, 2×2, 3×3 |
| Characteristic Equation | 2×2, 3×3 |
| Eigenvalues | 2×2 |
| Eigenvectors | 2×2 |
| Transpose | Any |

### Technical Limitations
- **Complex Numbers:** No support for complex eigenvalues/eigenvectors
- **Precision:** Standard floating-point limitations apply
- **Memory:** VLA size limited by available stack memory
- **Platform:** `system("clear")` command is Unix/Linux specific
- **Password:** Stored in plain text (security consideration)

---

## 🔮 Future Enhancements

Potential improvements for future versions:

- [ ] Support for larger matrices (4×4, 5×5, n×n)
- [ ] Gaussian elimination for general matrix operations
- [ ] LU decomposition implementation
- [ ] QR algorithm for larger eigenvalue problems
- [ ] Complex number support
- [ ] Matrix addition and subtraction
- [ ] File I/O for matrix data
- [ ] Encrypted password storage
- [ ] Matrix rank calculation
- [ ] RREF (Reduced Row Echelon Form)
- [ ] SVD (Singular Value Decomposition)
- [ ] Cross-platform compatibility (Windows/Mac/Linux)
- [ ] GUI version

---

## 🤝 Contributing

Contributions are welcome! Here's how you can help:

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
- Test thoroughly with various inputs
- Update documentation for new features
- Handle edge cases and errors appropriately

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
- Contact via email (add your email)

---

## 🙏 Acknowledgments

- Linear algebra algorithms based on standard mathematical formulations
- Inspired by the need for a simple, accessible matrix calculator
- Built with educational purposes in mind

---

## 📊 Project Status

**Current Version:** 3.2.4  
**Status:** Active Development  
**Last Updated:** December 24, 2025

---

**⚠️ Security Note:** The default password is `1`. For production use, change the password in the source code or implement a more secure authentication system.

**💡 Tip:** Press option 9 in the main menu to clear the screen for better visibility!