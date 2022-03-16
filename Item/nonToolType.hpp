/* File: nonToolType.hpp */
#ifndef __NON_TOOLTYPE_HPP__
#define __NON_TOOLTYPE_HPP__

#include <string>
using namespace std;

class Oak {
    private:
        string name;
        int id;
    public:
        Oak() {
            setName("OAK");
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

class Spruce {
    private:
        string name;
        int id;
    public:
        Spruce() {
            setName("Spruce");
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

class Birch {
    private:
        string name;
        int id;
    public:
        Birch() {
            setName("Birch");
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

class Cobblestone {
    private:
        string name;
        int id;
    public:
        Cobblestone() {
            setName("COBBLESTONE");
            setId(8);
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

class Blackstone {
    private:
        string name;
        int id;
    public:
        Blackstone() {
            setName("BLACKSTONE");
            setId(9);
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