#include <eosio/eosio.hpp>
#include <eosio/system.hpp>
// https://developers.eos.io/manuals/eosio.cdt/v1.7/upgrading/1.5-to-1.6
#include <eosio/permission.hpp>

// TIME 
// https://busy.org/@cmichel/advanced-eosio-programming-concepts

// BITS
// https://calc.penjee.com/

using namespace std;
using namespace eosio;

CONTRACT eosevolution : public contract
{
public:
  using contract::contract;

  ACTION create(name account);
  ACTION clear();
  ACTION time(name account);

private:
  TABLE genetic_world
  {
    name seed;
    string genes;
    uint64_t generation;
    auto primary_key() const { return seed.value; }
  };
  typedef multi_index<name("world"), genetic_world> genetic_world_table;
};
