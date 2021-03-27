#pragma once

#include <map>

#include "Block.h"
#include "Transaction.h"

class Blockchain {
   private:
    std::vector<Transaction> pending_transactions;
    std::vector<Block> chain;
    short difficulty;
    long long length = 0;

   public:
    Blockchain(short difficulty);
    Block make_genesis_block(std::string string_to_hash);
    Block get_last_block();
    Block add_new_block(std::map<std::string, std::string> data);
    bool is_chain_valid();
};
