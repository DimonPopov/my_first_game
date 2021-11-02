#pragma once 



class IElements;

class IFactory{
public:
    virtual ~IFactory(){}
    virtual IElements* createElement() = 0;
};