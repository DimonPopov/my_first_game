#pragma once

class Map_Iterator;
class Cell;

class Map{
    static Map* m_ptrMap;
    Cell** m_arrField;
    unsigned int m_width;
    unsigned int m_height;
    Map();
    Map(int, int);
    Map(Map& other) = delete;
	Map(Map&& other) = delete;
    Map& operator = (const Map&) = delete;
	Map&& operator = (const Map&&) = delete;
public:
    friend class Map_Iterator;
    static Map* getInstance();
    static Map* getInstance(int, int);
    ~Map();
};