#pragma once

#include "expr.hpp"
#include <iosfwd>

namespace exprs {

    //<editor-fold desc="number">
    class number : public expr_base {

    public:
        explicit number(double value);

        double evaluate(const variable_map_t &variables) const override;

        expr derive(const std::string &variable) const override;

        expr simplify() const override;

    private:
        double num;

        void write(std::ostream &out, WriteFormat fmt) const override;

        bool equals(const expr_base &b) const override;
    };
    //</editor-fold>


    //<editor-fold desc="variable">
    class variable : public expr_base {

    public:
        variable(std::string var);

        double evaluate(const variable_map_t &variables) const override;

        expr derive(const std::string &variable) const override;

        expr simplify() const override;

        std::string var;
    private:

        void write(std::ostream &out, WriteFormat fmt) const override;

        bool equals(const expr_base &b) const override;
    };
    //</editor-fold>


    //<editor-fold desc="operator plus">
    //Operator plus
    class operator_plus : public expr_base {

//        friend class expr;
        //When a class is declared a friend class, all the member functions of the friend class become friend functions.
        //Since ClassB is a friend class, we can create objects of ClassA inside of ClassB
        //Since ClassB is a friend class, we can access all members of ClassA from inside ClassB.

    public:
        operator_plus(expr a, expr b);

        double evaluate(const variable_map_t &variables) const override;

        expr derive(const std::string &variable) const override;

        expr simplify() const override;

    private:
        expr operand1;
        expr operand2;
        std::string sign;

        void write(std::ostream &out, WriteFormat fmt) const override;

        bool equals(const expr_base &b) const override;
    };
    //</editor-fold>


    //<editor-fold desc="operator minus">
    //Operator minus
    class operator_minus : public expr_base {

    public:
        operator_minus(expr a, expr b);

        double evaluate(const variable_map_t &variables) const override;

        expr derive(const std::string &variable) const override;

        expr simplify() const override;

    private:
        expr operand1;
        expr operand2;
        std::string sign;

        void write(std::ostream &out, WriteFormat fmt) const override;

        bool equals(const expr_base &b) const override;
    };
    //</editor-fold>


    //<editor-fold desc="operator multiply">
    //Operator multiply
    class operator_multiply : public expr_base {

    public:
        operator_multiply(expr a, expr b);

        double evaluate(const variable_map_t &variables) const override;

        expr derive(const std::string &variable) const override;

        expr simplify() const override;

    private:
        expr operand1;
        expr operand2;
        std::string sign;

        void write(std::ostream &out, WriteFormat fmt) const override;

        bool equals(const expr_base &b) const override;
    };
    //</editor-fold>


    //<editor-fold desc="operator divide">
    //Operator divide
    class operator_divide : public expr_base {

    public:
        operator_divide(expr a, expr b);

        double evaluate(const variable_map_t &variables) const override;

        expr derive(const std::string &variable) const override;

        expr simplify() const override;

    private:
        expr operand1;
        expr operand2;
        std::string sign;

        void write(std::ostream &out, WriteFormat fmt) const override;

        bool equals(const expr_base &b) const override;
    };
    //</editor-fold>


    //<editor-fold desc="operator pow">
    //Operator pow
    class operator_pow : public expr_base {

    public:
        operator_pow(expr m, expr e);

        double evaluate(const variable_map_t &variables) const override;

        expr derive(const std::string &variable) const override;

        expr simplify() const override;

    private:
        expr operand1;
        expr operand2;
        std::string sign;

        void write(std::ostream &out, WriteFormat fmt) const override;

        bool equals(const expr_base &b) const override;
    };
    //</editor-fold>


    //<editor-fold desc="operator sinus">
    //Operator sinus
    class operator_sinus : public expr_base {

    public:
        explicit operator_sinus(expr e);

        double evaluate(const variable_map_t &variables) const override;

        expr derive(const std::string &variable) const override;

        expr simplify() const override;

    private:
        expr operand1;
        std::string sign;

        void write(std::ostream &out, WriteFormat fmt) const override;

        bool equals(const expr_base &b) const override;
    };
    //</editor-fold>


    //<editor-fold desc="operator cosinus">
    //Operator cosinus
    class operator_cosinus : public expr_base {

    public:
        explicit operator_cosinus(expr e);

        double evaluate(const variable_map_t &variables) const override;

        expr derive(const std::string &variable) const override;

        expr simplify() const override;

    private:
        expr operand1;
        std::string sign;

        void write(std::ostream &out, WriteFormat fmt) const override;

        bool equals(const expr_base &b) const override;
    };
    //</editor-fold>


    //<editor-fold desc="operator log">
    //Operator log
    class operator_log : public expr_base {

    public:
        explicit operator_log(expr e);

        double evaluate(const variable_map_t &variables) const override;

        expr derive(const std::string &variable) const override;

        expr simplify() const override;

    private:
        expr operand1;
        std::string sign;

        void write(std::ostream &out, WriteFormat fmt) const override;

        bool equals(const expr_base &b) const override;
    };
    //</editor-fold>
}
