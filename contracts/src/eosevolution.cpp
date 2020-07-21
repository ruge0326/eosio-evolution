#include <eosevolution.hpp>

uint64_t eosevolution::getRandom(int max) {
  uint64_t A = eosio::tapos_block_num();
  uint64_t B = eosio::tapos_block_prefix();
  uint64_t C = A ^ B;
  uint64_t D = eosio::current_time_point().sec_since_epoch();
  uint64_t E = D<<32;
  uint64_t F = (C | E);
  uint64_t G = (F % max) + 1;
  eosio::print(":random:");
  eosio::print(G);
  return G;
}


ACTION eosevolution::time(int max) {
  getRandom(max);
}

ACTION eosevolution::create(name account)
{
  require_auth(get_self());
  check(is_account(account), "account does not exist");

  // uint32_t creation = eosio::get_account_creation_time(account).sec_since_epoch(); 
  // print(":creation:");
  // print(creation);

  living_being_table _population(get_self(), get_self().value);

  auto const world_itr = _population.find(account.value);
  if (world_itr == _population.end())
  {
    _population.emplace(get_self(), [&](auto &row) {
      row.seed = account;
    });
  } else {
    _population.modify(world_itr, get_self(), [&](auto &row) {
      row.seed = account;
    });
  }
}

ACTION eosevolution::clear()
{
  // require_auth(get_self());

  living_being_table _population(get_self(), get_self().value);

  auto world_itr = _population.begin();
  while (world_itr != _population.end())
  {
    world_itr = _population.erase(world_itr);
  }
}
