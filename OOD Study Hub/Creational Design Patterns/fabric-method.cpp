#include "fabric-method.h"


void TestFabricMethod() {
    //ConcreteCreatorA Creator_obj_a;
    //std::unique_ptr<ConcreteCreatorA> creatorA = std::make_unique<ConcreteCreatorA>(Creator_obj_a);
    auto creatorA = std::make_unique<ConcreteCreatorA>();
    auto productA = creatorA->createProduct();
    productA->use();
    //productA->havy_feature();

    auto creatorB = std::make_unique<ConcreteCreatorB>();
    auto productB = creatorB->createProduct();
    productB->use();
}