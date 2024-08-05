//
// Created by 吕翰琪 on 24-8-5.
//
#include "Factory.h"
#include <iostream>
#include <memory>
FactoryManager& FactoryManager::getInstance()
{
    static FactoryManager factorymanager;
    return factorymanager;
}

std::unique_ptr<Product>  FactoryManager::createProduct(const std::string &product_name)
{
    if (product_name == "ProductA") {
        // std::cout<<"successA"<<std::endl;
        return std::make_unique<ProductA>();
    } else if (product_name == "ProductB") {
        return std::make_unique<ProductB>();
    }else if (product_name == "ProductC") {
        return std::make_unique<ProductC>();
    }else {
        std::cerr << "Unknown product name: " << product_name << std::endl;
        return nullptr; // 或者抛出异常
    }
}
void Product::setStrategy(const std::string &name)
{
    this->strategy=name;
}
void Product::process()
{
    std::cout<<"I'am "<<strategy<<"."<<std::endl;
}
void FactoryManager::assignStrategy(Product* product,const std::string &strategy_name)
{
    product->setStrategy(strategy_name);
}
