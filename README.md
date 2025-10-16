# Cryptography Ciphers

## Overview
- This repository contains implementations of classical cryptography ciphers in **C**.
All ciphers in this repository are a basic implementation focused for learning rather than perfect production-grade ciphers. Upgrades to implemented ciphers will take place when I develop more skills in C. Advanced version of them will arrive in near future.
- I am also open to any feedback / improvements / and new ideas!


Currently implemented:
- [Vigenère Cipher](#vigenère-cipher-in-c)
- [Caesar Cipher](#caesar-cipher-in-c)
- [ROT13 Cipher](#ROT13-Cipher-in-C)
- [XOR Cipher](#XOR-Cipher-in-C)
- [Affine Cipher](#Affine-Cipher-in-C)

In progress:
- Hill Cipher


---

## Vigenère Cipher in C

The **Vigenère Cipher** is a classical method of encrypting alphabetic text by using a keyword to shift letters. Each letter of the plaintext is shifted based on a corresponding letter of the keyword.

This program provides a simple and functional example of the Vigenère cipher, allowing you to **encrypt** and **decrypt** text.



### Features
- Encrypt plaintext using a keyword
- Decrypt ciphertext using the same keyword
- Non-alphabet characters are ignored



### How It Works
1. User provides a text message.
2. User provides a keyword.
3. Each letter in the text is shifted based on the corresponding letter in the keyword.
4. The output is the encrypted or decrypted text.

**Encryption formula:**  
- Ciphertext = (Plaintext[i] + Key[i]) mod 26

**Decryption formula:**
- Plaintext = (Ciphertext[i] - Key[i] + 26) mod 26

---

## Caesar Cipher in C
The **Caesar Cipher** is one of the simplest and most widely known encryption techniques. Each letter in the plaintext is shifted a fixed number of positions down the alphabet.

This program provides a simple implementation in **C** that allows you to **encrypt** and **decrypt** text using a numeric key.

### Features
- Encrypt plaintext with a numeric key (0–25)
- Decrypt ciphertext with the same key
- Non-alphabet characters are preserved

### How It Works
1. User provides a text message.
2. User provides a numeric key (0–25).
3. Each letter in the text is shifted by the key.
4. Non-letter characters remain unchanged.
5. The output is the encrypted or decrypted text.


**Encryption formula:**  
- Ciphertext = (Plaintext[i] + Key) mod 26

**Decryption formula:**  
- Plaintext = (Ciphertext[i] - Key + 26) mod 26


---
## ROT13 Cipher in C

The ROT13 Cipher is a simple substitution cipher that shifts each letter of the alphabet by 13 positions. Since the alphabet has 26 letters, applying ROT13 twice returns the original text.

This program provides a minimal implementation in C that allows you to "encrypt" or "decrypt" text using the ROT13 method (both operations are the same).

---

## Features
- Encode or decode text using ROT13 (encryption and decryption are identical)  
- Non-alphabet characters are preserved  

---

## How It Works
1. User provides a text message.  
2. Each letter in the text is shifted forward by 13 places in the alphabet.  
   - If the letter passes 'Z' or 'z', it wraps back around to the start of the alphabet.  
3. Non-letter characters remain unchanged.  
4. The output is the transformed text.  

---

**Encryption formula:**  
- Ciphertext = (Plaintext[i] + ROT13) mod 26

**Decryption formula:**  
- Plaintext = (Ciphertext[i] + ROT13) mod 26

---
# XOR Cipher in C

The XOR Cipher is a simple method of encrypting text using the bitwise XOR operation.  
Each character of the plaintext is XOR-ed with a corresponding character of the keyword (repeated as needed).

This program provides a simple and functional example of the XOR cipher, allowing you to encrypt and decrypt text.

---

## Features
- Encrypt plaintext using a keyword
- Decrypt ciphertext using the same keyword
- Encrypted text is displayed in hexadecimal format
- Works with any character input (not limited to alphabetic text)

---

## How It Works
1. User provides a text message.
2. User provides a keyword.
3. Each character in the text is XOR-ed with the corresponding character of the keyword (key repeats if shorter than text).
4. Encrypted output is displayed as hexadecimal.
5. Decryption works by applying XOR again with the same key.

---

## Encryption Formula
- Ciphertext[i] = Plaintext[i] XOR Key[i% KeyLength]

## Decryption Formula
- Plaintext[i] = Ciphertext[i] XOR Key[i % KeyLength]

---

# Affine Cipher in C

The **Affine Cipher** is a type of monoalphabetic substitution cipher that combines both **multiplicative** and **additive** transformations. Each letter in the plaintext is encrypted using two keys: a **key multiplier (`a`)** and a **key (`b`)**.

This program provides a simple and interactive implementation in **C**, allowing you to encrypt and decrypt text using the Affine Cipher.

---

## Features
- Encrypt plaintext using keys `a` (key multiplier) and `b` (key)
- Decrypt ciphertext using the same keys
- Validates that the key multiplier has a modular inverse (ensuring decryption is possible)
- Preserves non-alphabet characters (spaces, punctuation, etc.)
- Handles both uppercase and lowercase letters
- Interactive menu with options for encryption, decryption, and exiting

---

## How It Works
1. User selects an option (Encrypt, Decrypt, or Exit).  
2. User provides a text message.  
3. User provides two integer keys:
   - **Key Multiplier (`a`)** – must have a modular inverse modulo 26  
   - **Key (`b`)** – additive key between 0–25  
4. Each alphabetic character is converted to a number (A=0, B=1, …, Z=25).  
5. The cipher applies modular arithmetic to perform encryption or decryption.  
6. Non-letter characters remain unchanged.  
7. The output is displayed on the screen.

---

## Encryption formula
- Ciphertext = (a * Plaintext[i] + b) mod 26

## Decryption formula
- Plaintext = a inverse * (Ciphertext[i] - b + 26) mod 26

---
**Resources**
- [Vigenere Cipher Wikipedia](https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher)
- [Vigenere Cipher GeeksforGeeks](https://www.geeksforgeeks.org/dsa/vigenere-cipher/)
- [Caesar Cipher Wikipedia](https://en.wikipedia.org/wiki/Caesar_cipher)
- [Caesar Cipher Splunk](https://www.splunk.com/en_us/blog/learn/caesar-cipher.html)
- [ROT13 Cipher Wikipedia](https://en.wikipedia.org/wiki/ROT13)
- [XOR Cipher Wikipedia](https://en.wikipedia.org/wiki/XOR_cipher)
- [Affine Cipher Wikipedia](https://en.wikipedia.org/wiki/Affine_cipher)


