#include <eosevolution.hpp>

uint64_t eosevolution::getRandom(int max) {
  uint32_t tbn = eosio::tapos_block_num();
  eosio::print(":tbn:");
  eosio::print(tbn);
  uint32_t tbp = eosio::tapos_block_prefix();
  eosio::print(":tbp:");
  eosio::print(tbp);
  uint32_t block = tbn ^ tbp;
  uint32_t block_time = eosio::current_time_point().sec_since_epoch();
  eosio::print(":block_time:");
  eosio::print(block_time);
  uint64_t random = random = ((((uint64_t)block_time<<32) | block) % max) + 1;
  eosio::print(":random:");
  eosio::print(random);
  return random;
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
