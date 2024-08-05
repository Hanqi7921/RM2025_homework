//
// Created by 吕翰琪 on 24-8-5.
//

#ifndef FACTORY_H
#define FACTORY_H

#include<string>
#include<memory>

class Product
{
protected:
    std::string strategy;
public:
    void process(); // 示例方法
    void setStrategy(const std::string &name);
};

class FactoryManager
{
public:
    static FactoryManager& getInstance();
    virtual std::unique_ptr<Product> createProduct(const std::string &product_name);
    virtual void assignStrategy(Product* product,const std::string &strategy_name);
private:
    FactoryManager()=default;
    ~FactoryManager()=default;
    FactoryManager(const FactoryManager &FactoryManager)=delete;
    const FactoryManager &operator=(const FactoryManager &FactoryManager)=delete;
};


class ProductA:public Product
{

};

class ProductB:public Product
{

};

class ProductC:public Product
{

};



#endif //FACTORY_H
