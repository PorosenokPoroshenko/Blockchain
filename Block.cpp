#include "headers/Block.h"

#include <iostream>
#include <string>

std::string Block::make_hash(std::string string_to_hash) {
    // using SHA256 algorithm to create hash
    SHA256 sha;
    sha.update(string_to_hash);
    std::string hash = SHA256::toString(sha.digest());
    return hash;
};

std::string Block::block_string() const {
    // converting time_point object to string
    std::time_t time_t_time =
        std::chrono::system_clock::to_time_t(this->timestamp);
    std::string timestamp = std::ctime(&time_t_time);
    timestamp.resize(timestamp.size() - 1);

    // make all keys and values of data a big string
    std::string data_string = "";
    for (auto it = this->data.begin(); it != this->data.end(); it++)
        data_string += it->first + it->second;

    std::string result = timestamp + this->previous_hash +
                         std::to_string(this->index) +
                         std::to_string(this->nonce) + data_string;
    return result;
}

Block::Block(long long int index, std::string previous_hash,
             std::map<std::string, std::string> data,
             std::chrono::_V2::system_clock::time_point timestamp) {
    this->data = data;
    this->previous_hash = previous_hash;
    this->timestamp = timestamp;
    this->index = index;

    std::string string_to_hash = this->block_string();
    this->hash = this->make_hash(string_to_hash);
};

bool Block::isValid(short difficulty) {
    // checks, if our block hash starts with zeros
    std::string difficulty_range = this->hash.substr(0, difficulty);
    return difficulty_range == std::string(difficulty, '0') ? true : false;
};

void Block::mine(short difficulty) {
    while (!this->isValid(difficulty)) {
        this->nonce++;
        std::string string_to_hash = this->block_string();
        this->hash = make_hash(string_to_hash);
    }
    std::cout << "Block is mined!! " << std::endl;
};

std::string Block::get_hash() const { return this->hash; }
std::string Block::get_previous_hash() const { return this->previous_hash; }

