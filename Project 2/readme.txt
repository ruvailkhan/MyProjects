Encryption is the process of encoding the data. iconverting plain text into ciphertext. This conversion is done with a key called an encryption key.

Decryption:


Decryption is the process of decoding the encoded data. Converting the ciphertext into plain text. This process requires a key that we used for encryption.

We require a key for encryption. There are two main types of keys used for encryption and decryption. They are Symmetric-key and Asymmetric-key.

Symmetric-key Encryption:

In symmetric-key encryption, the data is encoded and decoded with the same key. This is the easiest way of encryption, but also less secure. The receiver needs the key for decryption,
 so a safe way need for transferring keys. 
Anyone with the key can read the data in the middle.

Example:

Install the python cryptography library with the following command. 

pip install cryptography
Steps:

Import rsa library
Generate public and private keys with rsa.newkeys() method.
Encode the string to byte string.
Then encrypt the byte string with the public key.
Then the encrypted string can be decrypted with the private key.
The public key can only be used for encryption and the private can only be used for decryption.

Import Fernet
Then generate an encryption key, that can be used for encryption and decryption.
Convert the string to a byte string, so that it can be encrypted.
Instance the Fernet class with the encryption key.
Then encrypt the string with the Fernet instance.
Then it can be decrypted with Fernet class instance and it should be instanced with the same key used for encryption.