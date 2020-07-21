# eosio-evolution

EOSIO Evolution Game

### Setup

1. Create EOS Account on [testnet](https://monitor.jungletestnet.io/#home)
2. Complile

```
eosio-cpp -abigen -I include -R resource -contract eosevolution -o eosevolution.wasm src/eosevolution.cpp
```

### Random in EOSIO

[How to implement a pseudo random algorithm](https://github.com/rubenabix/eosio-evolution/blob/master/contracts/docs/Random_EOSIO.pdf)
