# Cryptography Ciphers

This repository contains implementations of classical cryptography ciphers in **C**.  
Currently implemented:
- Vigenère Cipher

---

## Vigenère Cipher in C

The **Vigenère Cipher** is a classical method of encrypting alphabetic text by using a keyword to shift letters. Each letter of the plaintext is shifted based on a corresponding letter of the keyword.

This program provides a simple and functional example of the Vigenère cipher, allowing you to **encrypt** and **decrypt** text.

---

### Features
- Encrypt plaintext using a keyword
- Decrypt ciphertext using the same keyword
- Non-alphabet characters are ignored

---

### How It Works
1. User provides a text message.
2. User provides a keyword.
3. Each letter in the text is shifted based on the corresponding letter in the keyword.
4. The output is the encrypted or decrypted text.

**Encryption formula:**  
- Ciphertext = (Plaintext[i] + Key[i]) mod 26

**Decryption formula:**
- Plaintext = (Ciphertext[i] - Key[i] + 26) mod 26

**Resources**
- [Vigenere Cipher Wikipedia](https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher)
- [Vigenere Cipher GeeksforGeeks](https://www.geeksforgeeks.org/dsa/vigenere-cipher/)
