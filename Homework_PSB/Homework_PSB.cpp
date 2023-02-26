
#include <iostream>

enum character
{
    character_playful,
    character_calm,
    character_angry
};

class Pet
{
protected:
    int nFLimbs;
    char* name;
public:
    Pet()
    {
        nFLimbs = 0;
        name = nullptr;
    }
    Pet(int _nFLimbs, char* _name)
    {
        nFLimbs = _nFLimbs;
        int size = strlen(_name);
        name = new char[size + 1];
        name[size] = '\0';
        for (int i = 0; i < size; i++)
        {
            name[i] = _name[i];
        }
    }

    void show()
    {
        std::cout << "Name: " << name << "\nnFLimbs: " << nFLimbs << '\n';
    }

    virtual ~Pet()
    {
        if (name != nullptr)
        {
            delete[] name;
        }
    }
};

class Cat : public Pet
{
private:
    bool furr;
    char* color;
public:
    Cat() : Pet()
    {
        furr = true;
        color = nullptr;
    }
    Cat(int _nFLimbs, char* _name, bool _furr, char* _color) : Pet(_nFLimbs, _name)
    {
        furr = _furr;
        if (_furr != false)
        {
            int size = strlen(_color);
            color = new char[size + 1];
            color[size] = '\0';
            for (int i = 0; i < size; i++)
            {
                color[i] = _color[i];
            }
        }
    }

    void show()
    {
        Pet::show();
        if (furr)
        {
            std::cout << "Furr: Yes\n" << "Color: " << color << '\n';
        }
    }

    ~Cat()
    {
        if (color != nullptr)
        {
            delete[] color;
        }
    }
};
class Dog : public Pet
{
private:
    bool longShout;
    character chrc;
public:
    Dog() : Pet()
    {
        longShout = false;
        chrc = character(0);
    }
    Dog(int _nFLimbs, char* _name, bool _longShout, character _chrc) : Pet(_nFLimbs, _name)
    {
        longShout = _longShout;
        chrc = _chrc;
    }

    void show()
    {
        Pet::show();
        std::cout << "Shout: " << (longShout ? "long" : "flat") << '\n'
            << "Character: " << (chrc ? "playful" : (chrc == 1 ? "calm" : "angry")) << '\n';
    }

};
class Bird : public Pet
{
private:
    bool smart;
    bool fly;
public:
    Bird() : Pet()
    {
        smart = true;
        fly = true;
    }
    Bird(int _nFLimbs, char* _name, bool _smart, bool _fly) : Pet(_nFLimbs, _name)
    {
        smart = _smart;
        fly = _fly;
    }

    void show()
    {
        Pet::show();
        std::cout << "Smart: " << (smart ? "Yes" : "No...") << '\n' << "Fly: " << (fly ? "can" : "can't") << '\n';
    }

};

class String
{
protected:
    char* str;
    int size;
public:
    String()
    {
        str = nullptr;
        size = 0;
    }
    String(int _size)
    {
        this->size = _size;
        this->str = new char[this->size + 1];
        this->str[this->size] = '\0';
    }
    String(char* _str)
    {
        copy(_str);
    }
    String(const char* _str)
    {
        copy(_str);
    }
    String(String& obj)
    {
        copy(obj);
    }

    void copy(char* _str)
    {
        this->size = strlen(_str) + 1;
        this->str = new char[size];
        this->str[size - 1] = '\0';
        for (int i = 0; i < size - 1; i++)
        {
            this->str[i] = _str[i];
        }
    }
    void copy(const char* _str)
    {
        this->size = strlen(_str) + 1;
        this->str = new char[size];
        this->str[size - 1] = '\0';
        for (int i = 0; i < size - 1; i++)
        {
            this->str[i] = _str[i];
        }
    }
    void copy(String& obj)
    {
        this->size = obj.size;
        this->str = new char[size];
        this->str[size - 1] = '\0';
        for (int i = 0; i < size - 1; i++)
        {
            this->str[i] = obj.str[i];
        }
    }

    int getLen() const
    {
        return size;
    }
    char* getStr() const
    {
        return str;
    }

    void Free()
    {
        delete[] str;
        str = nullptr;
        size = 0;
    }

    String operator=(String& obj)
    {
        copy(obj);
        return *this;
    }
    char* operator+(String& obj)
    {
        char* temp = new char[this->size + obj.getLen() + 1];
        temp[this->size + obj.getLen()] = '\0';
        for (int i = 0; i < this->size; i++)
        {
            temp[i] = this->str[i];
        }
        for (int i = 0; i < obj.getLen(); i++)
        {
            temp[size + i] = obj.getStr()[i];
        }
        return temp;
    }
    String operator+=(String& obj)
    {
        char* temp = new char[this->size + obj.getLen() + 1];
        temp[this->size + obj.getLen()] = '\0';
        for (int i = 0; i < this->size; i++)
        {
            temp[i] = this->str[i];
        }
        for (int i = 0; i < obj.getLen(); i++)
        {
            temp[size + i] = obj.getStr()[i];
        }
        if (this->str != nullptr)
        {
            delete[] this->str;
        }
        this->str = temp;
        temp = nullptr;
        this->size += obj.getLen();
        return *this;
    }
    bool operator==(String& obj)
    {
        bool check = false;
        if (this->size == obj.getLen())
        {
            check = true;
            for (int i = 0; i < this->size; i++)
            {
                if (this->str[i] != obj.getStr()[i])
                {
                    check = false;
                    break;
                }
            }
        }
        return check;
    }
    bool operator==(char* obj)
    {
        bool check = false;
        if (this->size == strlen(obj))
        {
            check = true;
            for (int i = 0; i < this->size; i++)
            {
                if (this->str[i] != obj[i])
                {
                    return false;
                }
            }
        }
        return check;
    }
    bool operator!=(String & obj)
    {
        if (this->size != obj.getLen())
        {
            return true;
        }
        else
        {
            for (int i = 0; i < this->size; i++)
            {
                if (this->str[i] != obj.getStr()[i])
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool operator!=(char* obj)
    {
        if (this->size != strlen(obj))
        {
            return true;
        }
        else
        {
            for (int i = 0; i < this->size; i++)
            {
                if (this->str[i] != obj[i])
                {
                    return true;
                }
            }
        }
        return false;
    }


    ~String()
    {
        if (str != nullptr)
        {
            delete[] str;
        }
    }
};

class BString : public String
{
private:
    bool pos;
    void bitCheck()
    {
        for (int i = 0; i < this->size - 1; i++)
        {
            if (this->str[i] != '0' && this->str[i] != '1')
            {
                this->Free();
                break;
            }
        }
    }
    char* plus(char* &obj, int _size)
    {
        char* temp = new char[_size + 1];
        bool next = false;
        temp[_size] = '\0';
        char* str_1 = new char[_size];
        str_1[_size - 1] = '\0';
        char* str_2 = new char[_size];
        str_2[_size - 1] = '\0';
        for (int i = 0; i < _size - 1; i++)
        {
            if (i < _size - 1 - (this->size - 1))
            {
                str_1[i] = '0';
            }
            else
            {
                str_1[i] = this->str[i - (_size - 1 - (this->size - 1))];
            }
        }
        for (int i = 0; i < _size - 1; i++)
        {
            if (i < _size - 1 - strlen(obj))
            {
                str_2[i] = '0';
            }
            else
            {
                str_2[i] = obj[i - (_size - 1 - strlen(obj))];
            }
        }
        for (int i = 0; i < _size; i++)
        {
            if (i < _size - 1)
            {
                if (str_1[_size - 2 - i] == '1' && str_2[_size - 2 - i] == '1')
                {
                    if (next)
                    {
                        temp[_size - 1 - i] = '1';
                    }
                    else
                    {
                        temp[_size - 1 - i] = '0';
                        next = true;
                    }
                }
                else if (str_1[_size - 2 - i] == '0' && str_2[_size - 2 - i] == '1' || str_1[_size - 2 - i] == '1' && str_2[_size - 2 - i] == '0')
                {
                    if (next)
                    {
                        temp[_size - 1 - i] = '0';
                    }
                    else
                    {
                        temp[_size - 1 - i] = '1';
                    }
                }
                else if (str_1[_size - 2 - i] == '0' && str_2[_size - 2 - i] == '0')
                {
                    if (next)
                    {
                        temp[_size - 1 - i] = '1';
                        next = false;
                    }
                    else
                    {
                        temp[_size - 1 - i] = '0';
                    }
                }
            }
            else
            {
                if (next)
                {
                    temp[_size - 1 - i] = '1';
                    next = false;
                }
                else
                {
                    temp[_size - 1 - i] = '0';
                }
            }
        }
        delete[] str_1;
        delete[] str_2;
        return temp;
    }
    char* minus(char* obj, int _size, bool n)
    {
        char* temp = new char[_size + 1];
        bool next = false;
        temp[_size] = '\0';
        char* str_1 = new char[_size + 1];
        str_1[_size] = '\0';
        char* str_2 = new char[_size + 1];
        str_2[_size] = '\0';
        std::cout << "str_1: ";
        for (int i = 0; i < _size; i++)
        {
            if (i < _size - (this->size - 1))
            {
                str_1[i] = '0';
            }
            else
            {
                str_1[i] = this->str[i - (_size - (this->size - 1))];
            }
            std::cout << str_1[i];
        }
        std::cout << '\n' << "str_2: ";
        for (int i = 0; i < _size; i++)
        {
            if (i < _size - strlen(obj))
            {
                str_2[i] = '0';
            }
            else
            {
                str_2[i] = obj[i - (_size - strlen(obj))];
            }
            std::cout << str_2[i];
        }
        std::cout << '\n';
        if (n)
        {
            for (int i = 0; i < _size; i++)
            {
                if (str_1[_size - 1 - i] == '1' && str_2[_size - 1 - i] == '1')
                {
                    if (next)
                    {
                        temp[_size - 1 - i] = '1';
                    }
                    else
                    {
                        temp[_size - 1 - i] = '0';
                    }
                }
                else if (str_1[_size - 1 - i] == '0' && str_2[_size - 1 - i] == '1')
                {
                    if (next)
                    {
                        temp[_size - 1 - i] = '0';
                        next = false;
                    }
                    else
                    {
                        temp[_size - 1 - i] = '1';
                    }
                }
                else if (str_1[_size - 1 - i] == '1' && str_2[_size - 1 - i] == '0')
                {
                    if (next)
                    {
                        temp[_size - 1 - i] = '0';
                    }
                    else
                    {
                        temp[_size - 1 - i] = '1';
                        next = true;
                    }
                }
                else if (str_1[_size - 1 - i] == '0' && str_2[_size - 1 - i] == '0')
                {
                    if (next)
                    {
                        temp[_size - 1 - i] = '1';
                    }
                    else
                    {
                        temp[_size - 1 - i] = '0';
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < _size; i++)
            {
                if (str_1[_size - 1 - i] == '1' && str_2[_size - 1 - i] == '1')
                {
                    if (next)
                    {
                        temp[_size - 1 - i] = '1';
                    }
                    else
                    {
                        temp[_size - 1 - i] = '0';
                    }
                }
                else if (str_1[_size - 1 - i] == '0' && str_2[_size - 1 - i] == '1')
                {
                    if (next)
                    {
                        temp[_size - 1 - i] = '0';
                    }
                    else
                    {
                        temp[_size - 1 - i] = '1';
                        next = true;
                    }
                }
                else if (str_1[_size - 1 - i] == '1' && str_2[_size - 1 - i] == '0')
                {
                    if (next)
                    {
                        temp[_size - 1 - i] = '0';
                        next = false;
                    }
                    else
                    {
                        temp[_size - 1 - i] = '1';
                    }
                }
                else if (str_1[_size - 1 - i] == '0' && str_2[_size - 1 - i] == '0')
                {
                    if (next)
                    {
                        temp[_size - 1 - i] = '1';
                    }
                    else
                    {
                        temp[_size - 1 - i] = '0';
                    }
                }
            }
        }
        delete[] str_1;
        delete[] str_2;
        return temp;
    }

public:
    BString() : String()
    {
        pos = true;
    }
    BString(char* _str) : String(_str)
    {
        pos = true;
        bitCheck();
    }
    BString(BString& obj) : String(obj.getStr())
    {
        this->pos = obj.pos;
    }

    void changePos()
    {
        if (pos)
        {
            pos = false;
        }
        else
        {
            pos = true;
        }
    }

    BString operator=(BString& obj)
    {
        String::copy(obj.str);
        this->pos = obj.pos;
        return *this;
    }
    char* operator+(BString& obj)
    {
        char* temp = nullptr;
        if (this->pos == obj.pos)
        {
            if (this->size == obj.size)
            {
                return plus(obj.str, this->size + 1);

            }
            else if (this->size > obj.size)
            {
                return plus(obj.str, this->size + 1);
            }
            else
            {
                return plus(obj.str, obj.size + 1);
            }
        }
        else
        {
            if (this->size == obj.size)
            {
                for (int i = 0; i < this->size; i++)
                {
                    if (this->str[i] == '1' && obj.str[i] == '0')
                    {
                        return minus(obj.str, this->size, false);
                    }
                    else if (this->str[i] == '0' && obj.str[i] == '1')
                    {
                        return minus(obj.str, this->size, true);
                    }
                }
            }
            else if (this->size > obj.size)
            {
                return minus(obj.str, this->size, false);
            }
            else
            {
                return minus(obj.str, obj.size, true);
            }
        }
    }
    BString operator+=(BString& obj)
    {
        char* temp = nullptr;
        if (this->pos == obj.pos)
        {
            if (this->size == obj.size)
            {
                temp = plus(obj.str, this->size + 1);
            }
            else if (this->size > obj.size)
            {
                temp = plus(obj.str, this->size + 1);
            }
            else
            {
                temp = plus(obj.str, obj.size + 1);
            }
            delete[] this->str;
            this->copy(temp);
            delete[] temp;
            return *this;
        }
        else
        {
            if (this->size == obj.size)
            {
                for (int i = 0; i < this->size; i++)
                {
                    if (this->str[i] == '1' && obj.str[i] == '0')
                    {
                        temp = minus(obj.str, this->size, false);
                    }
                    else if (this->str[i] == '0' && obj.str[i] == '1')
                    {
                        temp = minus(obj.str, this->size, true);
                    }
                }
            }
            else if (this->size > obj.size)
            {
                temp = minus(obj.str, this->size, false);
            }
            else
            {
                temp = minus(obj.str, obj.size, true);
            }
            delete[] this->str;
            this->copy(temp);
            delete[] temp;
            return *this;
        }
    }
    bool operator==(BString& obj)
    {
        if (this->pos == obj.pos)
        {
            bool check = false;
            if (this->size == obj.size)
            {
                check = true;
                for (int i = 0; i < this->size; i++)
                {
                    if (this->str[i] != obj.str[i])
                    {
                        check = false;
                        break;
                    }
                }
            }
            return check;
        }
        return false;
    }
    bool operator!=(BString& obj)
    {
        if (this->pos == obj.pos)
        {
            return false;
        }

    }
    
    ~BString()
    {
        //Task say what we need destructor. We have destrcutor.
    }
};

int main()
{
    if (false)
    {
        char* name = new char[3]; name[0] = '0'; name[1] = '1'; name[2] = '\0';
        Bird test(4, name, 1, 1);
        test.show();
        delete[] name;
    }
    char* test1 = new char[5]; test1[0] = '1'; test1[1] = '1'; test1[2] = '0'; test1[3] = '0'; test1[4] = '\0';
    char* test2 = new char[3]; test2[0] = '1'; test2[1] = '0'; test2[2] = '\0';
    BString bits_1(test1); BString bits_2(test2);
    std::cout << "first: " << test1 << '\n' << "second: " << test2 << '\n';
    char* help = bits_1 + bits_2;
    std::cout << help << '\n';
    bits_2.changePos();
    help = bits_1 + bits_2;
    std::cout << help << '\n';

    delete[] help;
    delete[] test1;
    delete[] test2;
}