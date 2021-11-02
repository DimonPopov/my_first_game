#pragma once

#include <iostream>
#include <memory>

#include "../Elements/IElement.h"
#include "../Elements/Object.h"


class Cell{
    std::shared_ptr<IElements> object;
    int m_value;
public:
    Cell();
    int getValue();
    void reValue(int newValue);
    std::shared_ptr<IElements> getObj();
    void reObj(std::shared_ptr<IElements> newObj);
};