#include <iostream>
#include <vector>


struct Blecha {
    Blecha() {
        std::cout << "Blecham\n";
    }

    ~Blecha() {
        std::cout << "Pomocc\n";
    }
};

class Clovek {
public:
    virtual void write(std::ostream &out) const {
        out << "Tady jsem clovekem\n";
    }

    virtual ~Clovek() = default;
};

class Cely_clovek : public Clovek {
public:
    Cely_clovek(const std::string &jmeno) : jmeno(jmeno) {}

    virtual void write(std::ostream &out) const {
        out << jmeno;
    }

    ~Cely_clovek() override = default;

private:
    std::string jmeno;
};

class Mimozemstan : public Clovek {
public:
    Mimozemstan(double jmeno) : jmeno(jmeno) {}

    virtual void write(std::ostream &out) const {
        out << jmeno;
    }

    ~Mimozemstan() override = default;

private:
    double jmeno;
};

class Skupina : public Clovek {
public:
    Skupina(const std::string &prefix, const std::string &separator, const std::string &postfix) : prefix(prefix),
                                                                                                   separator(separator),
                                                                                                   postfix(postfix) {}

    void write(std::ostream &out) const override {
        out << prefix;
        int i = 0;
        for (auto &elem: m_data) {
            if (i++ != 0) {
                out << separator;
            }
            elem->write(out);
        }
        out << postfix;
    }

    void push_back(Clovek *clovek) {
        m_data.push_back(std::unique_ptr<Clovek>(clovek));
    }

private:
    std::vector<std::unique_ptr<Clovek>> m_data;
    std::string prefix, separator, postfix;
};

class Student : public Clovek {
public:
    void write(std::ostream &out) const override {
        out << "Tady jsem studentem\n";
    }

    Blecha Fu;

    ~Student() override = default;
};

class Dite : public Clovek {
public:
    void write(std::ostream &out) const override {
        out << "MA-MA\n";
    }

    ~Dite() override = default;
};

std::ostream &operator<<(std::ostream &out, const Clovek &clovek) {
    clovek.write(out);
    return out;
}

int main() {
    Skupina skupina("{", ", ", "}\n");
    skupina.push_back(new Cely_clovek("Honza"));
    skupina.push_back(new Cely_clovek("Viktor"));
    skupina.push_back(new Mimozemstan(3.14));
    skupina.push_back(new Mimozemstan(112));

    skupina.write(std::cout);

    Skupina *skupina1 = new Skupina("(", ", ", ")");
    skupina1->push_back(new Cely_clovek("Milanek"));
    skupina1->push_back(new Mimozemstan(2.72));

    skupina.push_back(skupina1);
    skupina.push_back(new Mimozemstan(165));

    skupina.write(std::cout);

    std::cout << skupina;
}
