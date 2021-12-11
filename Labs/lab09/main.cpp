#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>
#include <cmath>
#include <sstream>

struct Blecha {
    Blecha() { std::cout << "Jsem tady, HAHAHA!\n"; };

    ~Blecha() { std::cout << "Au, nekdo mne zastipl!!!\n"; };
};

class Clovek {
public:
    virtual void write(std::ostream &out) const { out << "Tady jsem clovekem\n"; }

    virtual ~Clovek() = default;

    c // = 0, protoze metoda je abstraktni
};

class Student : public Clovek {
public:
    Blecha Bedriska;

    void write(std::ostream &out) const override { out << "Ucim se C++\n"; }

    ~Student() override = default;
};

class Duchodce : public Clovek {
public:
    void write(std::ostream &out) const override { out << "Moje kosti do stareho zeleza\n"; }

    ~Duchodce() override = default;
};

class Cely_clovek : public Clovek {
public:
    Cely_clovek(std::string n) : name(std::move(n)) {};

    void write(std::ostream &out) const override { out << "Jmenuji se " << name; }

    std::unique_ptr<Clovek>clone() const override {
        return std::make_unique<Cely_clovek>(*this);
    }

    ~Cely_clovek() override = default;

private:
    std::string name;
};


class cos_exception : public std::exception{

public:
    cos_exception(double num) : num(num) {
        std::ostringstream tmp;
        tmp << "Pro hodnotu " << num << " je cos(" << num << ") = " << std::cos(num);
        tmp << " a to je zaporne\n";
        str = tmp.str();
    }
    const char * what() const noexcept override {return str.c_str();}

private:
    double num;
    std::string str;
};


class Mimozemstan : public Clovek {
public:
    Mimozemstan(double n) : num(n) {
        if(std::cos(n) < 0){
            throw cos_exception(num);
        }
    };

    void write(std::ostream &out) const override { out << "Moje cislo je " << num; }

    Mimozemstan *clone() const override{
        return new Mimozemstan(*this);
    }

    ~Mimozemstan() override = default;

private:
    double num;
};

class Group : public Clovek {
public:
    Group(std::string pre, std::string in, std::string post) :
            prefix(std::move(pre)),
            infix(std::move(in)),
            postfix(std::move(post)) {}

    void write(std::ostream &out) const override {
        out << prefix;
        int i = 0;
        for (auto &elem: data) {
            if (i++) out << infix;
            elem->write(out);
        }
        out << postfix;
    }
    Group *clone() const override{
        return new Group(*this);
    }
    void swap(Group &rhs) {
        data.swap(rhs.data);
        prefix.swap(rhs.prefix);
        postfix.swap(rhs.postfix);
        infix.swap(rhs.infix);
    }

    Group(Group &&rhs) {
        swap(rhs);
    }

    Group(const Group &rhs) :
            prefix(rhs.prefix),
            postfix(rhs.postfix),
            infix(rhs.infix) { //kopirujici konstruktor
        for(auto &elem : rhs.data){
            data.push_back(std::unique_ptr<Clovek>(elem->clone()));
        }
    }

    Group &operator=(const Group &rhs) {
        auto tmp(rhs);
        swap(tmp);
        return *this;
    }

    Group &operator=(Group &&rhs) {
        swap(rhs);
        return *this;
    }


    void push_back(std::unique_ptr<Clovek> elem) {
        data.push_back(std::move(elem));
    }

    ~Group() override = default;

private:
    std::vector<std::unique_ptr<Clovek>> data;
    std::string prefix;
    std::string infix;
    std::string postfix;
};

std::ostream &operator<<(std::ostream &out, const Clovek &c) {
    c.write(out);
    return out;
}

int main() {
    try{
        Group g("(", ", ", ")\n");
        g.push_back(std::make_unique<Cely_clovek>("Petr"));
        g.push_back(std::make_unique<Cely_clovek>("Pavel"));
        g.push_back(std::make_unique<Mimozemstan>(5));
        g.push_back(std::make_unique<Mimozemstan>(3.141592));
        std::cout << g;
        Group *gg = new Group("[", "| ", "]");
        gg->push_back(std::make_unique<Mimozemstan>(1.5789));
        gg->push_back(std::make_unique<Cely_clovek>("Renata"));
        g.push_back(std::make_unique<Group>(std::move(*gg)));
        std::cout << g;
    } catch (std::exception& e){
        std::cerr << e.what() << std::endl;
    } catch (...){
        std::cerr << "Dunno" << std::endl;
    }
//    std::unique_ptr<Clovek> Jan(new Clovek);
//    std::unique_ptr<Clovek>  Albert(new Student);
//    std::unique_ptr<Clovek>  Alena(new Duchodce);
//    Duchodce Antonin{};
//    Jan->write(std::cout);
//    Albert->write(std::cout);
//    Alena->write(std::cout);
//    Antonin.write(std::cout);
//    std::unique_ptr<Clovek>  Petr(new Cely_clovek("Petr"));
//    std::unique_ptr<Clovek>  Pavel(new Cely_clovek("Pavel"));
//    std::unique_ptr<Clovek>  Cislo5(new Mimozemstan(3.141592));
//    std::unique_ptr<Clovek>  IT(new Mimozemstan(2.7845122));
}
