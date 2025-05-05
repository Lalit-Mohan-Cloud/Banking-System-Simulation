# 🏦 Banking System in C++

## 📋 Overview
    This is a simple console-based Banking System written in C++. It simulates basic banking operations such as:
       - Opening a Saving or Current account
       - Crediting money into the account
       - Debiting money from the account
       - Checking balance
       - Printing account details
    All user data is saved in individual text files named after the account holder.

## 🛠️ Features
   - Unique 14-digit account number generation
   - Saving and current account creation
   - Balance updates for debit/credit operations
   - Data storage using plain text files
   - Menu-driven interface with user-friendly prompts

## 🧾 Account Rules
   - A saving account can be opened with any initial deposit.
   - A current account requires a minimum deposit of ₹10,000.

## 💡 How It Works
   - User selects whether to open a new account or perform a transaction.
   - Based on user input, the program navigates to:
   - Saving/Current account creation with personal details
   - Transaction options: debit, credit, balance inquiry, or account detail display
   - User data is stored/retrieved using .txt files.

## 📂 File Structure
    Each user account is saved as:
       -> <username>.txt

    Containing:
               - Name
               - Father's Name
               - Mobile Number
               - Aadhar Number
               - Address
               - Account Number
               - Balance

## 🚀 How to Run
    Make sure you have a C++ compiler installed (e.g., g++).
        1. Compile the code:
        2. g++ -o bank_app main.cpp
        3. Run the program:
        4. ./bank_app  # On Linux/Mac
        5. bank_app.exe  # On Windows

## 🔐 Sample Input
    - Enter O or o for opening an account and T or t for the transaction: o
    - Type s or S for saving or c or C for current: s
    - Enter your name: John Doe
    - Enter your father's name: David Doe
    ...

## ✅ Future Improvements
    - Password protection and login system
    - File encryption for sensitive data
    - GUI interface for better usability
    - Database integration (e.g., SQLite or MySQL)

## 👨‍💻 Author
    Developed by: Lalit Mohan

