# Cryptography Ciphers

This repository contains implementations of classical cryptography ciphers in **C**.
All ciphers in this repository are a basic implementation focused on learning rather than perfect production grade ciphers. Advanced version of them
will arrive in near future.

Currently implemented:
- [Vigenère Cipher](#vigenère-cipher-in-c)
- [Caesar Cipher](#caesar-cipher-in-c)

In progress:
- More ciphers


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

**Resources**
- [Vigenere Cipher Wikipedia](https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher)
- [Vigenere Cipher GeeksforGeeks](https://www.geeksforgeeks.org/dsa/vigenere-cipher/)
- [Caesar Cipher Wikipedia](https://en.wikipedia.org/wiki/Caesar_cipher)
- [Caesar Cipher Splunk](https://www.splunk.com/en_us/blog/learn/caesar-cipher.html)


