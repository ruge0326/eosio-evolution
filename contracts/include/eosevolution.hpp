#include <eosio/eosio.hpp>

using namespace std;
using namespace eosio;

CONTRACT eosevolution : public contract
{
public:
  using contract::contract;

  ACTION create(name account);
  ACTION clear();

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
