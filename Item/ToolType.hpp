/* File: ToolType.hpp */
#ifndef __TOOLTYPE_HPP__
#define __TOOLTYPE_HPP__

#include <string>
using namespace std;

class Wooden {
    private:
        string name;
        int id;
    public:
        Wooden() {
            setName("WOODEN");
            setId(0);
        }

        void setName(string name) {
            this->name = name;
        }

        string getName() const {
            return this->name;
        }

        void setId(int id) {
            this->id = id;
        }

        int getId() const {
            return this->id;
        }
};

class Stone {
    private:
        string name;
        int id;
    public:
        Stone() {
            setName("STONE");
            setId(1);
        }

        void setName(string name) {
            this->name = name;
        }

        string getName() const {
            return this->name;
        }

        void setId(int id) {
            this->id = id;
        }

        int getId() const {
            return this->id;
        }
};

class Iron {
    private:
        string name;
        int id;
    public:
        Iron() {
            setName("IRON");
            setId(2);
        }

        void setName(string name) {
            this->name = name;
        }

        string getName() const {
            return this->name;
        }

        void setId(int id) {
            this->id = id;
        }

        int getId() const {
            return this->id;
        }
};

class Diamond {
    private:
        string name;
        int id;
    public:
        Diamond() {
            setName("DIAMOND");
            setId(3);
        }

        void setName(string name) {
            this->name = name;
        }

        string getName() const {
            return this->name;
        }

        void setId(int id) {
            this->id = id;
        }

        int getId() const {
            return this->id;
        }
};

#endif