#include <eosio/eosio.hpp>
#include <eosio/system.hpp>
#include <stdlib.h> // srand, rand
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
  ACTION time(int max);

private:

  uint64_t getRandom(int max);

  TABLE living_being
  {
    name seed;
    uint32_t genesa; // 1 color plus byte // #DE4848
    uint32_t genesb; // 1 color plus byte
    uint32_t genesc; // 1 color plus byte
    uint32_t genesd; // 1 color plus byte
    uint32_t kind; //
    
    uint64_t birth_date; //
    auto primary_key() const { return seed.value; }
  };
  typedef multi_index<name("population"), living_being> living_being_table;
};
