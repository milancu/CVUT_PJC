#include "expr_impl.hpp"

#include <iostream>
#include <utility>
#include <valarray>

namespace exprs {

    //<editor-fold desc="number">
    //Number
    number::number(double value) :
            num(value) {};

    void number::write(std::ostream &out, expr_base::WriteFormat fmt) const {
        out << num;
    }

    double number::evaluate(const expr_base::variable_map_t &variables) const {
        return num;
    }

    expr number::derive(const std::string &variable) const {
        return expr::ZERO;
    }

    expr number::simplify() const {
        return shared_from_this();
    }

    bool number::equals(const expr_base &b) const {
        auto expr = dynamic_cast<number const *>(b.shared_from_this().get());
        return (expr->num. == this->num);
    }
    //</editor-fold>


    //<editor-fold desc="variable">
    //Variable
    variable::variable(std::string name) {
    }

    void variable::write(std::ostream &out, expr_base::WriteFormat fmt) const {
        out << var;
    }

    double variable::evaluate(const expr_base::variable_map_t &variables) const {
        if (variables.find(var) == variables.end()) {
            throw unbound_variable_exception("");
        }
        return variables.at(var);
    }

    expr variable::derive(const std::string &variable) const {
        if (variable != var) {
            return expr::ZERO;
        }
        return expr::ONE;
    }

    expr variable::simplify() const {
        return shared_from_this();
    }

    bool variable::equals(const expr_base &b) const {
        if (const variable *value = dynamic_cast<variable const *>(b.shared_from_this().get())) {
            return value->var == var;
        }
    }
    //</editor-fold>


    //<editor-fold desc="operator plus">
    //Operator plus
    operator_plus::operator_plus(expr a, expr b) :
            operand1(std::move(a)),
            operand2(std::move(b)) { sign = "+"; }

    void operator_plus::write(std::ostream &out, expr_base::WriteFormat fmt) const {
        if (fmt == expr_base::WriteFormat::Infix) {
            out << "(" << fmt_expr{operand1, fmt} << sign << fmt_expr{operand2, fmt} << ")";
        } else if (fmt == expr_base::WriteFormat::Postfix) {
            out << "(" << fmt_expr{operand1, fmt} << " " << fmt_expr{operand2, fmt} << " " << sign << ")";
        } else if (fmt == expr_base::WriteFormat::Prefix) {
            out << "(" << sign << " " << fmt_expr{operand1, fmt} << " " << fmt_expr{operand2, fmt} << ")";
        }
    }

    double operator_plus::evaluate(const expr_base::variable_map_t &variables) const {
        return operand1->evaluate(variables) + operand2->evaluate(variables);
    }

    expr operator_plus::derive(const std::string &variable) const {
        return std::make_shared<operator_plus>(operand1->derive(variable), operand2->derive(variable));
    }

    expr operator_plus::simplify() const {
        expr op1 = operand1->simplify();
        expr op2 = operand2->simplify();
        if (op1 == expr::ZERO) {
            return op2->shared_from_this();
        } else if (op2 == expr::ZERO) {
            return op1->shared_from_this();
        } else {
            return std::make_shared<exprs::operator_plus>(op1, op2);
        }
    }

    bool operator_plus::equals(const expr_base &b) const {
        auto expr = dynamic_cast<operator_plus const *>(b.shared_from_this().get());
        return (expr->operand1 == this->operand1 && expr->operand2 == this->operand2);
    }
    //</editor-fold>


    //<editor-fold desc="operator minus">
    //Operator minus
    operator_minus::operator_minus(expr a, expr b) :
            operand1(std::move(a)),
            operand2(std::move(b)) { sign = "-"; }

    void operator_minus::write(std::ostream &out, expr_base::WriteFormat fmt) const {
        if (fmt == expr_base::WriteFormat::Infix) {
            out << "(" << fmt_expr{operand1, fmt} << sign << fmt_expr{operand2, fmt} << ")";
        } else if (fmt == expr_base::WriteFormat::Postfix) {
            out << "(" << fmt_expr{operand1, fmt} << " " << fmt_expr{operand2, fmt} << " " << sign << ")";
        } else if (fmt == expr_base::WriteFormat::Prefix) {
            out << "(" << sign << " " << fmt_expr{operand1, fmt} << " " << fmt_expr{operand2, fmt} << ")";
        }
    }

    double operator_minus::evaluate(const expr_base::variable_map_t &variables) const {
        return operand1->evaluate(variables) - operand2->evaluate(variables);
    }

    expr operator_minus::derive(const std::string &variable) const {
        return std::make_shared<operator_minus>(operand1->derive(variable), operand2->derive(variable));
    }

    expr operator_minus::simplify() const {
        expr op1 = operand1->simplify();
        expr op2 = operand2->simplify();
        if (op1 == expr::ZERO) {
            return op2;
        }
        return std::make_shared<exprs::operator_minus>(operator_minus(op1, op2));
    }


    bool operator_minus::equals(const expr_base &b) const {
        auto expr = dynamic_cast<operator_minus const *>(b.shared_from_this().get());
        return (expr->operand1 == this->operand1 && expr->operand2 == this->operand2);
    }
    //</editor-fold>


    //<editor-fold desc="operator multiply">
    //Operator multiply
    operator_multiply::operator_multiply(expr a, expr b) :
            operand1(std::move(a)),
            operand2(std::move(b)) { sign = "*"; }

    void operator_multiply::write(std::ostream &out, expr_base::WriteFormat fmt) const {
        if (fmt == expr_base::WriteFormat::Infix) {
            out << "(" << fmt_expr{operand1, fmt} << sign << fmt_expr{operand2, fmt} << ")";
        } else if (fmt == expr_base::WriteFormat::Postfix) {
            out << "(" << fmt_expr{operand1, fmt} << " " << fmt_expr{operand2, fmt} << " " << sign << ")";
        } else if (fmt == expr_base::WriteFormat::Prefix) {
            out << "(" << sign << " " << fmt_expr{operand1, fmt} << " " << fmt_expr{operand2, fmt} << ")";
        }
    }

    double operator_multiply::evaluate(const expr_base::variable_map_t &variables) const {
        return operand1->evaluate(variables) * operand2->evaluate(variables);
    }

    expr operator_multiply::derive(const std::string &variable) const {
        auto f = std::make_shared<operator_multiply>(operand1->derive(variable), operand2);
        auto g = std::make_shared<operator_multiply>(operand1, operand2->derive(variable));
        return std::make_shared<operator_plus>(operator_plus(f, g));
    }

    expr operator_multiply::simplify() const {
        expr op1 = operand1->simplify();
        expr op2 = operand2->simplify();
        if (op1 == expr::ZERO || op2 == expr::ZERO) {
            return expr::ZERO;
        } else if (op2 == expr::ONE) {
            return op1->shared_from_this();
        } else if (op2 == expr::ONE) {
            return op2->shared_from_this();
        } else {
            return std::make_shared<operator_multiply>(op1, op2);
        }
    }

    bool operator_multiply::equals(const expr_base &b) const {
        auto expr = dynamic_cast<operator_multiply const *>(b.shared_from_this().get());
        return (expr->operand1 == this->operand1 && expr->operand2 == this->operand2);
    }
    //</editor-fold>


    //<editor-fold desc="operator divide">
    //Operator divide
    operator_divide::operator_divide(expr a, expr b) :
            operand1(std::move(a)),
            operand2(std::move(b)) { sign = "/"; }

    void operator_divide::write(std::ostream &out, expr_base::WriteFormat fmt) const {
        if (fmt == expr_base::WriteFormat::Infix) {
            out << "(" << fmt_expr{operand1, fmt} << sign << fmt_expr{operand2, fmt} << ")";
        } else if (fmt == expr_base::WriteFormat::Postfix) {
            out << "(" << fmt_expr{operand1, fmt} << " " << fmt_expr{operand2, fmt} << " " << sign << ")";
        } else if (fmt == expr_base::WriteFormat::Prefix) {
            out << "(" << sign << " " << fmt_expr{operand1, fmt} << " " << fmt_expr{operand2, fmt} << ")";
        }
    }

    double operator_divide::evaluate(const expr_base::variable_map_t &variables) const {
        return operand1->evaluate(variables) / operand2->evaluate(variables);
    }

    expr operator_divide::derive(const std::string &variable) const {
        auto f = std::make_shared<operator_multiply>(operand1->derive(variable), operand2);
        auto g = std::make_shared<operator_multiply>(operand1, operand2->derive(variable));
        auto ff = std::make_shared<operator_minus>(operator_minus(f, g));
        auto gg = std::make_shared<operator_pow>(operator_pow(expr::number(2), operand2));
        return std::make_shared<operator_divide>(operator_divide(ff, gg));
    }

    expr operator_divide::simplify() const {
        expr op1 = operand1->simplify();
        expr op2 = operand2->simplify();
        if (op1 == expr::ZERO && op2 == expr::ZERO) {
            return shared_from_this();
        } else if (op1 == expr::ZERO) {
            return expr::ZERO;
        } else if (op2 == expr::ONE) {
            return op1->shared_from_this();
        } else {
            return std::make_shared<operator_divide>(operator_divide(op1, op2));
        }
    }

    bool operator_divide::equals(const expr_base &b) const {
        auto expr = dynamic_cast<operator_divide const *>(b.shared_from_this().get());
        return (expr->operand1 == this->operand1 && expr->operand2 == this->operand2);
    }
    //</editor-fold>


    //<editor-fold desc="operator pow">
    //Operator pow
    operator_pow::operator_pow(expr m, expr e) :
            operand1(std::move(m)),
            operand2(std::move(e)) { sign = "^"; }

    void operator_pow::write(std::ostream &out, expr_base::WriteFormat fmt) const {
        if (fmt == expr_base::WriteFormat::Infix) {
            out << "(" << fmt_expr{operand1, fmt} << sign << fmt_expr{operand2, fmt} << ")";
        } else if (fmt == expr_base::WriteFormat::Postfix) {
            out << "(" << fmt_expr{operand1, fmt} << " " << fmt_expr{operand2, fmt} << " " << sign << ")";
        } else if (fmt == expr_base::WriteFormat::Prefix) {
            out << "(" << sign << " " << fmt_expr{operand1, fmt} << " " << fmt_expr{operand2, fmt} << ")";
        }
    }

    double operator_pow::evaluate(const expr_base::variable_map_t &variables) const {
        return pow(operand1->evaluate(variables), operand2->evaluate(variables));
    }

    expr operator_pow::derive(const std::string &variable) const {
        expr fdg = std::make_shared<operator_pow>(operator_pow(operand1, operand2));
        expr fdMg = std::make_shared<operator_multiply>(operator_multiply(operand1->derive(variable), operand2));
        expr fdMgDg = std::make_shared<operator_divide>(operator_divide(fdMg, operand2));
        expr fMgd = std::make_shared<operator_multiply>(operator_multiply(log(operand1), operand2->derive(variable)));
        auto fdMgDgPfMgd = std::make_shared<operator_plus>(operator_plus(fdMgDg, fMgd));
        return std::make_shared<operator_multiply>(operator_multiply(fdg, fdMgDgPfMgd));
    }

    expr operator_pow::simplify() const {
        expr op1 = operand1->simplify();
        expr op2 = operand2->simplify();
        if (op2 == expr::ZERO) {
            return expr::ONE;
        } else if (op2 == expr::ONE) {
            return op1->shared_from_this();
        } else if (op1 == expr::ZERO) {
            return expr::ZERO;
        } else {
            return std::make_shared<operator_pow>(operator_pow(op1, op2));
        }
    }

    bool operator_pow::equals(const expr_base &b) const {
        auto expr = dynamic_cast<operator_pow const *>(b.shared_from_this().get());
        return (expr->operand1 == this->operand1 && expr->operand2 == this->operand2);
    }
    //</editor-fold>


    //<editor-fold desc="operator sinus">
    //Operator sinus
    operator_sinus::operator_sinus(expr e) :
            operand1(std::move(e)) { sign = "sin"; }

    void operator_sinus::write(std::ostream &out, expr_base::WriteFormat fmt) const {
        if (fmt == expr_base::WriteFormat::Infix) {
            out << "(" << fmt_expr{operand1, fmt} << sign << ")";
        } else if (fmt == expr_base::WriteFormat::Postfix) {
            out << "(" << fmt_expr{operand1, fmt} << " " << sign << ")";
        } else if (fmt == expr_base::WriteFormat::Prefix) {
            out << "(" << sign << " " << fmt_expr{operand1, fmt} << ")";
        }
    }

    double operator_sinus::evaluate(const expr_base::variable_map_t &variables) const {
        return std::sin(operand1->evaluate(variables));
    }

    expr operator_sinus::derive(const std::string &variable) const {
        auto Cf = std::make_shared<operator_cosinus>(operator_cosinus(operand1));
        auto f = operand1->derive(variable);
        return std::make_shared<operator_multiply>(operator_multiply(Cf, f));
    }

    expr operator_sinus::simplify() const {
        expr op1 = operand1->simplify();
        return std::make_shared<operator_sinus>(operator_sinus(op1));
    }

    bool operator_sinus::equals(const expr_base &b) const {
        auto expr = dynamic_cast<operator_sinus const *>(b.shared_from_this().get());
        return (expr->operand1 == this->operand1);
    }
    //</editor-fold>


    //<editor-fold desc="operator cosinus">
    //Operator cosinus
    operator_cosinus::operator_cosinus(expr e) :
            operand1(std::move(e)) { sign = "cos"; }

    void operator_cosinus::write(std::ostream &out, expr_base::WriteFormat fmt) const {
        if (fmt == expr_base::WriteFormat::Infix) {
            out << "(" << fmt_expr{operand1, fmt} << sign << ")";
        } else if (fmt == expr_base::WriteFormat::Postfix) {
            out << "(" << fmt_expr{operand1, fmt} << " " << sign << ")";
        } else if (fmt == expr_base::WriteFormat::Prefix) {
            out << "(" << sign << " " << fmt_expr{operand1, fmt} << ")";
        }
    }

    double operator_cosinus::evaluate(const expr_base::variable_map_t &variables) const {
        return std::cos(operand1->evaluate(variables));
    }

    expr operator_cosinus::derive(const std::string &variable) const {
        auto Sf = std::make_shared<operator_sinus>(operator_sinus(operand1));
        auto f = operand1->derive(variable);
        auto MSf = std::make_shared<operator_minus>(expr::ZERO, Sf);
        return std::make_shared<operator_multiply>(operator_multiply(MSf, f));
    }

    expr operator_cosinus::simplify() const {
        expr op1 = operand1->simplify();
        return std::make_shared<operator_cosinus>(operator_cosinus(op1));
    }

    bool operator_cosinus::equals(const expr_base &b) const {
        auto expr = dynamic_cast<operator_cosinus const *>(b.shared_from_this().get());
        return (expr->operand1 == this->operand1);
    }
    //</editor-fold>


    //<editor-fold desc="operator log">
    //Operator log
    operator_log::operator_log(expr e) :
            operand1(std::move(e)) { sign = "log"; }

    void operator_log::write(std::ostream &out, expr_base::WriteFormat fmt) const {
        if (fmt == expr_base::WriteFormat::Infix) {
            out << "(" << fmt_expr{operand1, fmt} << sign << ")";
        } else if (fmt == expr_base::WriteFormat::Postfix) {
            out << "(" << fmt_expr{operand1, fmt} << " " << sign << ")";
        } else if (fmt == expr_base::WriteFormat::Prefix) {
            out << "(" << sign << " " << fmt_expr{operand1, fmt} << ")";
        }
    }

    double operator_log::evaluate(const expr_base::variable_map_t &variables) const {
        return std::log(operand1->evaluate(variables));

    }

    expr operator_log::derive(const std::string &variable) const {
//        auto fd = std::make_shared<expr>(operand1->derive(variable));
        auto fd = operand1->derive(variable);
        return std::make_shared<operator_divide>(fd, operand1);
    }

    expr operator_log::simplify() const {
        expr op1 = operand1->simplify();
        if (op1 == expr::ONE) {
            return expr::ZERO;
        }
        return std::make_shared<operator_log>(operator_log(op1));
    }

    bool operator_log::equals(const expr_base &b) const {
        auto expr = dynamic_cast<operator_log const *>(b.shared_from_this().get());
        return (expr->operand1 == this->operand1);
    }
    //</editor-fold>
}
