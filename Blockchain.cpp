#include "headers/Blockchain.h"

#include <iostream>

#include "headers/Block.h"

Block Blockchain::make_genesis_block(std::string string_to_hash) {
    // creating genesis block(the first block in blockchain)
    std::string genesis_block_hash = Block::make_hash(string_to_hash);
    Block genesis_block(0, genesis_block_hash, {},
                        std::chrono::_V2::system_clock::now());
    return genesis_block;
};

Block Blockchain::get_last_block() { return this->chain.back(); }

Blockchain::Blockchain(short difficulty) {
    std::string string_to_hash =
        "Govno, zalupa, penis, kher, davalka, khuy, blyadina Golovka, "
        "shlyukha, zhopa, chlen, yeblan, petukh… mudila Rukoblud, ssanina, "
        "ochko, blyadun, vagina Suka, yeblanishche, vlagalishche, perdun, "
        "drochila Pidor, pizda, tuz, malaf'ya Gomik, mudila, pilotka, manda "
        "Anus, vagina, putana, pedrila Shalava, khuila, moshonka";
    Block genesis_block = this->make_genesis_block(string_to_hash);
    this->chain = {genesis_block};
    this->difficulty = difficulty;
};

Block Blockchain::add_new_block(std::map<std::string, std::string> data) {
    this->length++;
    std::string previous_hash = this->get_last_block().get_hash();
    auto timestamp = std::chrono::_V2::system_clock::now();

    Block new_block(this->length, previous_hash, data, timestamp);
    new_block.mine(this->difficulty);

    this->chain.push_back(new_block);
    std::cout << "BLOCK ADDED " << this->get_last_block().get_hash()
              << std::endl;
    return new_block;
};

bool Blockchain::is_chain_valid() {
    for (int i = 1; i < this->length; i++) {
        const Block current_block = this->chain[i];
        const Block previous_block = this->chain[i - 1];

        if (current_block.get_hash() !=
            current_block.make_hash(current_block.block_string()))
            return false;

        if (current_block.get_previous_hash() != previous_block.get_hash())
            return false;
    }
    return true;
};

