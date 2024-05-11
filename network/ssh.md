#### Connect to a machine with ssh

You can connect to a machine with ssh enabled using 

```
ssh username@ipadress
```

For example

```
ssh johncarmack@192.168.100.120
```

After login into a remote machine you will be asked to provide the password of `username`.

Sometimes you want to avoid typing the password everytime and you can create a key to log into a remote
machine. The following section explains how to set up a key.


#### Create up an ssh key

You can use `ssh-keychain` to create a key-pair.


Let us create a key using algorithm `ed25519` and 100 rounds and store the private and remote key in `~/.ssh/id_ed25519`. This is done with the command

```
ssh-keygen -t ed25519 -a 100 -f ~/.ssh/id_ed25519 
```

which will produce two files in folder `~/.ssh/`. Let-s look at them


```
ls ~/.ssh/
```

Here are the two files:

```
id_ed25519
id_ed25519.pub		
```



For more details about the options of `ssh-keygen`, the documentation states:


```
-a rounds: When saving a private key, this option specifies the number of KDF 
           (key derivation function, currently bcrypt_pbkdf(3)) rounds used. 
           Higher numbers result in slower passphrase verification and increased 
           resistance to brute-force password cracking (should the keys be stolen).
           The default is 16 rounds.

-b bits: Specifies the number of bits in the key to create. For RSA keys,
         the minimum size is 1024 bits and the default is 3072 bits. 
         Generally, 3072 bits is considered sufficient.
         DSA keys must be exactly 1024 bits as specified by FIPS 186-2.
         For ECDSA keys, the -b flag determines the key length by selecting
         from one of three elliptic curve sizes: 256, 384 or 521 bits.
         Attempting to use bit lengths other than these three values for ECDSA keys will fail.
         ECDSA-SK, Ed25519 and Ed25519-SK keys have a fixed length and 
         the -b flag will be ignored.

-o : Save the private-key using the new OpenSSH format rather than the PEM format.
     This option doesn't appear anymore in the Man page, and thus it should be okay
     to be omitted.

-f filename: Specifies the filename of the key file.

-N: New passphrase

-q: Silence ssh-keygen

-t dsa | ecdsa | ecdsa-sk | ed25519 | ed25519-sk | rsa: Specifies the type of key to create.

```

Note that, the higher `-a` values you pass the slower passphrase verification and increased resistance to brute-force password cracking. Therefore use high `-a` values such as 100 to have high security.



#### Copy the Public key to the remte machine


Now that we have generated an SSH key pair, and we can copy the public  key to the server we want to connect to. The public key is the one that finishes with `.pub`. In our case `id_ed25519.pub`.


To do this we can use `ssh-copy-id` as follows

```
ssh-copy-id -i ~/.ssh/path_public_key -p port username@ip
```

which for example could be

```
ssh-copy-id -i ~/.ssh/id_ed25519.pub johncarmack@192.168.100.120
```