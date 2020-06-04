#include <eosevolution.hpp>

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
