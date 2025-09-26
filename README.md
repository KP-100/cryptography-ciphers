# Cryptography Ciphers

## Overview
- This repository contains implementations of classical cryptography ciphers in **C**.
All ciphers in this repository are a basic implementation focused on learning rather than perfect production grade ciphers. Upgrades to implemented ciphers will take place when I develop more skills in C. Advanced version of them will arrive in near future.
- I am also open to any feedback / improvements / and new ideas!


Currently implemented:
- [Vigenère Cipher](#vigenère-cipher-in-c)
- [Caesar Cipher](#caesar-cipher-in-c)
- [ROT13 Cipher](#ROT13-Cipher-in-C)

In progress:
- XOR Cipher
- Mode Operation


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

**Resources**
- [Vigenere Cipher Wikipedia](https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher)
- [Vigenere Cipher GeeksforGeeks](https://www.geeksforgeeks.org/dsa/vigenere-cipher/)
- [Caesar Cipher Wikipedia](https://en.wikipedia.org/wiki/Caesar_cipher)
- [Caesar Cipher Splunk](https://www.splunk.com/en_us/blog/learn/caesar-cipher.html)
- [ROT13 Cipher Wikipedia](https://en.wikipedia.org/wiki/ROT13)


