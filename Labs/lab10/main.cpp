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
    virtual void write(std::ostream& out) const = 0;
    virtual std::unique_ptr<Clovek> clone() const = 0;
    virtual ~Clovek() = default;
};
class Student : public Clovek {
public:
    Blecha Bedriska;
    void write(std::ostream& out) const override { out << "Ucim se C++\n"; }
    ~Student() override = default;
};
class Duchodce : public Clovek {
public:
    void write(std::ostream& out) const override { out << "Moje kosti do stareho zeleza\n"; }
    ~Duchodce() override = default;
};
class Cely_clovek : public Clovek {
public:
    Cely_clovek(std::string n) : name(std::move(n)) {};
    void write(std::ostream& out) const override { out << name; }
    std::unique_ptr<Clovek> clone() const override { return std::make_unique<Cely_clovek>(*this); }
    ~Cely_clovek() override = default;
private:
    std::string name;
};
class cos_exception : public std::exception {
public:
    cos_exception(double n) : n(n) {
        std::ostringstream s;
        s << "Pro cislo " << n << " je cos(" << n << ") = " << std::cos(n);
        s << " a to je zaporne!\n";
        str = s.str();
    }
    const char * what() const noexcept override { return str.c_str(); }
private:
    double n;
    std::string str;
};
class Mimozemstan : public Clovek {
public:
    Mimozemstan(double n) : num(n) {
        if (std::cos(n) < 0)
            throw cos_exception(n);
    };
    void write(std::ostream& out) const override { out << num; }
    std::unique_ptr<Clovek> clone() const override { return std::make_unique<Mimozemstan>(*this); }
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
    void write(std::ostream& out) const override {
        out << prefix;
        int i = 0;
        for (auto& elem : data) {
            if (i++) out << infix;
            elem->write(out);
        }
        out << postfix;
    }
    std::unique_ptr<Clovek> clone() const override { return std::make_unique<Group>(*this); }
    void swap(Group& rhs) {
        data.swap(rhs.data);
        prefix.swap(rhs.prefix);
        infix.swap(rhs.infix);
        postfix.swap(rhs.postfix);
    }
    Group(Group&& rhs) { swap(rhs); }
    Group& operator=(Group&& rhs) {swap(rhs); return *this; }
    Group(const Group& rhs) :
        prefix(rhs.prefix),
        infix(rhs.infix),
        postfix(rhs.postfix)
    {
        for (auto& elem : rhs.data)
            data.push_back(elem->clone());
    }
    Group& operator=(const Group& rhs) {
        auto tmp(rhs);
        swap(tmp);
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
std::ostream& operator<<(std::ostream& out, const Clovek& c) {
    c.write(out);
    return out;
}
int main() {
    try {
        Group g("(", ", ", ")\n");
        g.push_back(std::make_unique<Cely_clovek>("Petr"));
        g.push_back(std::make_unique<Cely_clovek>("Pavel"));
        g.push_back(std::make_unique<Mimozemstan>(9));
        g.push_back(std::make_unique<Mimozemstan>(3.141592));
        std::cout << g;
        Group *gg = new Group("[", "| ", "]");
        gg->push_back(std::make_unique<Mimozemstan>(1.5789));
        gg->push_back(std::make_unique<Cely_clovek>("Renata"));
        g.push_back(std::make_unique<Group>(*gg));
        std::cout << g;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}