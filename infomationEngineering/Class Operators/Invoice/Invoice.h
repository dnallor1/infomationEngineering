#pragma once
#include <iostream>
#include <vector>

class Item{
    std::string name;
    double unit_net_price;
    char VAT_tax_type;
    int total_amount;
public:
    Item(std::string name_ = "", double U_N_P = 0, char V_T_T = ' ', int T_Amnt= 0 );
    std::string get_name();
    double get_price();
    char get_vat();
    int get_amount();

};
class Invoice{
    std::string seller_nip;
    std::string buyer_nip;
    std::vector<Item> items;
public:
    Invoice(std::string s_nip= "0", std::string b_nip= "0");
    void add_item(const Item &item);
    friend std::ostream &operator<<(std::ostream &str, Invoice &rhs);
};

