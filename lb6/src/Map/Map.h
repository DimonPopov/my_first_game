#pragma once

#include <memory>
#include "../Elements/Factory/IFactory.h"
#include "../Save/SaveClass.h"

class LogClass;
class Iterator;
class Cell;

class Map{
    static std::shared_ptr<Map> m_ptrMap;
    std::unique_ptr<std::unique_ptr<Cell[]>[]> m_arrField;
    std::shared_ptr<LogClass> logger;
    unsigned m_width;
    unsigned m_height;
    Map();
    Map(unsigned, unsigned);
    Map(Map& other) = delete;
	Map(Map&& other) = delete;
    Map& operator = (const Map&) = delete;
	Map&& operator = (const Map&&) = delete;
public:
    friend class SaveClass;
    friend class Iterator;
    static std::shared_ptr<Map> getInstance();
    static std::shared_ptr<Map> getInstance(unsigned, unsigned);
    unsigned getWidth();
    unsigned getHeight();
    unsigned getCellValue(const unsigned x, const unsigned y);
    std::shared_ptr<LogClass> getLogger();
};