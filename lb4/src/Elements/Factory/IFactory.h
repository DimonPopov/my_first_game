#pragma once 

#include <memory>

class IElements;

class IFactory{
public:
    virtual std::shared_ptr<IElements> createElement() = 0;
};