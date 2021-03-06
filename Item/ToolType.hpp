/* File: ToolType.hpp */
#ifndef __TOOLTYPE_HPP__
#define __TOOLTYPE_HPP__

#include <string>
using namespace std;

class WoodenType
{
private:
    string name;
    int id;

public:
    WoodenType()
    {
        setName("WOODEN");
        setId(0);
    }

    void setName(string name)
    {
        this->name = name;
    }

    string getName() const
    {
        return this->name;
    }

    void setId(int id)
    {
        this->id = id;
    }

    int getId() const
    {
        return this->id;
    }
};

class StoneType
{
private:
    string name;
    int id;

public:
    StoneType()
    {
        setName("STONE");
        setId(1);
    }

    void setName(string name)
    {
        this->name = name;
    }

    string getName() const
    {
        return this->name;
    }

    void setId(int id)
    {
        this->id = id;
    }

    int getId() const
    {
        return this->id;
    }
};

class IronType
{
private:
    string name;
    int id;

public:
    IronType()
    {
        setName("IRON");
        setId(2);
    }

    void setName(string name)
    {
        this->name = name;
    }

    string getName() const
    {
        return this->name;
    }

    void setId(int id)
    {
        this->id = id;
    }

    int getId() const
    {
        return this->id;
    }
};

class DiamondType
{
private:
    string name;
    int id;

public:
    DiamondType()
    {
        setName("DIAMOND");
        setId(3);
    }

    void setName(string name)
    {
        this->name = name;
    }

    string getName() const
    {
        return this->name;
    }

    void setId(int id)
    {
        this->id = id;
    }

    int getId() const
    {
        return this->id;
    }
};

#endif