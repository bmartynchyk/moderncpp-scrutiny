#pragma once

#include <iostream>
#include <memory>

class Product {
public:
    virtual ~Product() = default;
    virtual void use() = 0;
    //virtual void havy_feature() = 0;
};

class ConcreteProductA : public Product {
public:
    void use() override {
        std::cout << "Using ConcreteProductA" << std::endl;
    }

    void havy_feature() {
        std::cout << "Using havy_feature of product A - building house" << std::endl;
    }
};

class ConcreteProductB : public Product {
public:
    void use() override {
        std::cout << "Using ConcreteProductB" << std::endl;
    }

    void havy_feature() {
        std::cout << "Using havy_feature of product B - assemble computer" << std::endl;
    }
};

class Creator {
public:
    virtual ~Creator() = default;
    virtual std::unique_ptr<Product> createProduct() = 0;
};

class ConcreteCreatorA : public Creator {
public:
    std::unique_ptr<Product> createProduct() override {
        return std::make_unique<ConcreteProductA>();
    }
};

class ConcreteCreatorB : public Creator {
public:
    std::unique_ptr<Product> createProduct() override {
        return std::make_unique<ConcreteProductB>();
    }
};

void TestFabricMethod();