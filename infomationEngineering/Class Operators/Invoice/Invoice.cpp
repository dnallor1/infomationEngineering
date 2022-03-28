#include <iostream>
#include "Invoice.h"
#include <vector>

Item::Item(std::string name_, double U_N_P, char V_T_T, int T_Amnt){
    name = name_;
    unit_net_price = U_N_P;
    VAT_tax_type = V_T_T;
    total_amount = T_Amnt;
}

Invoice::Invoice(std::string s_nip, std::string b_nip){
    seller_nip = s_nip;
    buyer_nip = b_nip;
}
void Invoice::add_item(const Item &item){
    items.emplace_back(item);
}
std::string Item::get_name(){
    return name;
}
double Item::get_price(){
    return unit_net_price;
};
char Item::get_vat(){
    return VAT_tax_type;
};
int Item::get_amount(){
    return total_amount;
};
std::ostream &operator<<(std::ostream &str, Invoice &rhs){
    double net_sum=0;
    double sum=0;
    int i=1;
    str << "------------------VAT invoice------------------" << std::endl
        << "===============================================" << std::endl
        << "Seller:"<<rhs.seller_nip<<"              "<< "Buyer:"<< rhs.buyer_nip << std::endl
        << "                  c.j. VAT   il.    net   total\n";
    for(auto item: rhs.items)    {
        double p_net = item.get_price()*item.get_amount();
        double p_vat=0;
        if(item.get_vat() == 'A') p_vat = p_net*1.23;
        else if(item.get_vat() == 'B') p_vat = p_net*1.08;
        else if(item.get_vat() == 'C') p_vat = p_net;
        str << i<<'.'<<item.get_name()<<"       | "<<item.get_price()<<" "<<item.get_vat()<<" | "<<item.get_amount()<<" | "<<p_net<<" | " <<p_vat<<'\n';
        net_sum+=p_net;
        sum+=p_vat;
        i++;
    }
    str << "\n------------------------------------ TOTAL ----\n"
        << "                                  " << net_sum << '|' << sum;
    return str;
}
