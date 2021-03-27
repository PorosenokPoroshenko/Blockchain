#pragma once

#include <chrono>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "SHA256/include/SHA256.h"

class Block {
   private:
    // std::vector<Transaction> transactions;
    std::map<std::string, std::string> data;
    std::string previous_hash;
    std::string hash;
    std::chrono::_V2::system_clock::time_point timestamp;
    long long int index;
    int nonce = 0;

    bool isValid(short difficulty);

   public:
    Block(long long int index, std::string previous_hash,
          std::map<std::string, std::string> data,
          std::chrono::_V2::system_clock::time_point timestamp);
    static std::string make_hash(std::string string_to_hash);
    void mine(short int difficulty);

    std::string block_string() const;
    std::string get_hash() const;
    std::string get_previous_hash() const;
};
