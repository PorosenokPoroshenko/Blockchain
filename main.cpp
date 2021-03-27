#include <iostream>

#include "headers/Blockchain.h"
#include "headers/Data.h"
int main() {
    short difficulty = 15;
    std::string json_path = "data.json";
    std::map<std::string, std::string> data{
        {"payer", "alex"}, {"payee", "demetry"}, {"amount", "1000000"}};
    Blockchain hoholcoin(difficulty);
    std::map<std::string, std::string> data2{
        {"payer", "pizda"}, {"payee", "hui"}, {"amount", "1.005141"}};

    hoholcoin.add_new_block(data);
    hoholcoin.add_new_block(data2);

    std::cout << "Is blockchain valid " << hoholcoin.is_chain_valid()
              << std::endl;
}

