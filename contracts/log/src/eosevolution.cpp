#include <eosevolution.hpp>

ACTION eosevolution::time(name account) {
  auto creation = eosio::get_account_creation_time(account).time_since_epoch().count(); 
  print(":creation:");
  print(creation);
  int i;
  for (i = 1; i <= 1000; i += 2) { 
  }
  auto block_time = eosio::current_time_point().time_since_epoch().count();
  eosio::print(":block_time:");
  eosio::print(block_time);
}

ACTION eosevolution::create(name account)
{
  require_auth(get_self());
  check(is_account(account), "account does not exist");

  genetic_world_table _world(get_self(), get_self().value);

  auto world_itr = _world.find(account.value);
  if (world_itr == _world.end())
  {
    _world.emplace(get_self(), [&](auto &row) {
      row.seed = account;
      row.genes = "";
      row.generation = 1;
    });
  }
}

ACTION eosevolution::clear()
{
  require_auth(get_self());

  genetic_world_table _world(get_self(), get_self().value);

  auto world_itr = _world.begin();
  while (world_itr != _world.end())
  {
    world_itr = _world.erase(world_itr);
  }
}
