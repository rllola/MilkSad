# Milk Sad vulnerability

This project reproduce the vulnerability found in libbitcoin named "Milk Sad". The lib replaced its random number generator by a pseudo one relying timestamp for entropy.

All the credits to the Milk Sad team fo their work (https://milksad.info/).

## How to use it 

```
$ make build
$ mt19937
```

The python script just showed the seed being transformed into the mnemonic to found the infamous Milk Sad mnemonic used with a 0 timestamp.