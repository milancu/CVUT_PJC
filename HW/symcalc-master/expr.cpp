#include "expr.hpp"
#include "expr_impl.hpp"
#include "tokenizer.hpp"
#include <stdexcept>
#include <stack>
#include <sstream>
#include <utility>
#include <iostream>

const expr expr::ZERO = expr::number(0.0);
const expr expr::ONE = expr::number(1.0);

// TODO: overloaded operators +, -, *, /, functions pow, log, sin, cos,
//       expr::number, expr::variable, operator==, operator<<,
//       create_expression_tree

expr expr::number(double n) {
    return std::make_shared<exprs::number>(exprs::number(n));
}

expr expr::variable(std::string name) {
    return std::make_shared<exprs::variable>(exprs::variable(std::move(name)));
}

expr create_expression_tree(const std::string &expression) {
    auto output = std::deque<expr>();
    auto stackOfExpr = std::stack<Token>();
    std::istringstream is(expression);
    Tokenizer tokenizer = Tokenizer(is);
    expr x, y;
    bool need_oper = false;
    TokenId prevToken = TokenId::End;

    while (true) {
        Token tokenHelper = tokenizer.next();
        switch (tokenHelper.id) {
            case TokenId::End:
                if (output.empty()) {
                    throw parse_error("missing numbers");
                }
                while (!stackOfExpr.empty() && stackOfExpr.top().id != TokenId::LParen) {
                    if (stackOfExpr.top().id == TokenId::LParen || stackOfExpr.top().id == TokenId::RParen)
                        throw parse_error("parenthesis don't match");
                    if (stackOfExpr.top().id == TokenId::Plus) {
                        if (output.size() < 2) throw parse_error("not enough numbers");
                        if (output.empty()) break;
                        x = output.back();
                        output.pop_back();
                        if (output.empty()) break;
                        y = output.back();
                        output.pop_back();
                        output.push_back(y + x);
                        stackOfExpr.pop();
                        if (stackOfExpr.empty()) break;
                    } else if (stackOfExpr.top().id == TokenId::Minus) {
                        if (output.size() < 2) throw parse_error("not enough numbers");
                        x = output.back();
                        output.pop_back();
                        y = output.back();
                        output.pop_back();
                        output.push_back(y - x);
                        stackOfExpr.pop();
                        if (stackOfExpr.empty()) break;
                    } else if (stackOfExpr.top().id == TokenId::Multiply) {
                        if (output.size() < 2) throw parse_error("not enough numbers");
                        x = output.back();
                        output.pop_back();
                        y = output.back();
                        output.pop_back();
                        output.push_back(y * x);
                        stackOfExpr.pop();
                        if (stackOfExpr.empty()) break;
                    } else if (stackOfExpr.top().id == TokenId::Divide) {
                        if (output.size() < 2) throw parse_error("not enough numbers");
                        x = output.back();
                        output.pop_back();
                        y = output.back();
                        output.pop_back();
                        output.push_back(y / x);
                        stackOfExpr.pop();
                        if (stackOfExpr.empty()) break;
                    } else if (stackOfExpr.top().id == TokenId::Power) {
                        if (output.size() < 2) throw parse_error("not enough numbers");
                        x = output.back();
                        output.pop_back();
                        y = output.back();
                        output.pop_back();
                        output.push_back(pow(y, x));
                        stackOfExpr.pop();
                        if (stackOfExpr.empty()) break;
                    } else {
                        throw tokenize_error("attempt to apply unknown thing");
                    }
                }
                break;
            case TokenId::Number:
                if (need_oper) throw parse_error("missing operation");
                need_oper = true;
                output.push_back(expr::number(tokenHelper.number));
                break;
            case TokenId::Identifier:
                if (need_oper) throw parse_error("missing operation");
                need_oper = true;
                if (tokenHelper.identifier == "sin"
                    ||
                    tokenHelper.identifier == "cos"
                    ||
                    tokenHelper.identifier == "log") {
                    stackOfExpr.push(tokenHelper);
                    break;
                }
                output.push_back(expr::variable(tokenHelper.identifier));
                break;
            case TokenId::LParen:
                need_oper = false;
                stackOfExpr.push(tokenHelper);
                break;
            case TokenId::RParen: {
                if (output.empty()) throw parse_error("missing numbers");
                if (prevToken == TokenId::LParen) throw parse_error("missing left parenthesis");
                need_oper = true;
                if (stackOfExpr.empty()) break;
                while (stackOfExpr.top().id != TokenId::LParen) {
                    if (stackOfExpr.empty()) break;
                    if (stackOfExpr.top().identifier == "sin"
                        ||
                        stackOfExpr.top().identifier == "cos"
                        ||
                        stackOfExpr.top().identifier == "log") {
                        if (output.empty()) throw parse_error("not enough numbers to apply function");
                        x = output.back();
                        output.pop_back();
                        if (stackOfExpr.top().identifier == "sin") output.push_back(sin(x));
                        if (stackOfExpr.top().identifier == "cos") output.push_back(cos(x));
                        if (stackOfExpr.top().identifier == "log") output.push_back(log(x));
                        stackOfExpr.pop();
                    }
                    if (stackOfExpr.empty()) break;
                    if (stackOfExpr.top().id == TokenId::Plus) {
                        if (output.size() < 2) throw parse_error("not enough numbers");
                        x = output.back();
                        output.pop_back();
                        y = output.back();
                        output.pop_back();
                        output.push_back(y + x);
                        stackOfExpr.pop();
                        if (stackOfExpr.empty()) break;
                    }
                    if (stackOfExpr.top().id == TokenId::Minus) {
                        if (output.size() < 2) throw parse_error("not enough numbers");
                        x = output.back();
                        output.pop_back();
                        y = output.back();
                        output.pop_back();
                        output.push_back(y - x);
                        stackOfExpr.pop();
                        if (stackOfExpr.empty()) break;
                    }
                    if (stackOfExpr.top().id == TokenId::Multiply) {
                        if (output.size() < 2) throw parse_error("not enough numbers");
                        x = output.back();
                        output.pop_back();
                        y = output.back();
                        output.pop_back();
                        output.push_back(y * x);
                        stackOfExpr.pop();
                        if (stackOfExpr.empty()) break;
                    }
                    if (stackOfExpr.top().id == TokenId::Divide) {
                        if (output.size() < 2) throw parse_error("not enough numbers");
                        x = output.back();
                        output.pop_back();
                        y = output.back();
                        output.pop_back();
                        output.push_back(y / x);
                        stackOfExpr.pop();
                        if (stackOfExpr.empty()) break;
                    }
                    if (stackOfExpr.top().id == TokenId::Power) {
                        if (output.size() < 2) throw parse_error("not enough numbers");
                        x = output.back();
                        output.pop_back();
                        y = output.back();
                        output.pop_back();
                        output.push_back(pow(y, x));
                        stackOfExpr.pop();
                        if (stackOfExpr.empty()) break;
                    }
                }
                if (stackOfExpr.empty()) break;
                stackOfExpr.pop();
                if (stackOfExpr.empty()) break;
                if (stackOfExpr.top().identifier == "sin"
                    ||
                    stackOfExpr.top().identifier == "cos"
                    ||
                    stackOfExpr.top().identifier == "log") {
                    if (output.empty()) throw parse_error("not enough numbers to apply function");
                    x = output.back();
                    output.pop_back();
                    if (stackOfExpr.top().identifier == "sin") output.push_back(sin(x));
                    if (stackOfExpr.top().identifier == "cos") output.push_back(cos(x));
                    if (stackOfExpr.top().identifier == "log") output.push_back(log(x));
                    stackOfExpr.pop();
                }
                break;

                case TokenId::Plus:
                case TokenId::Minus:
                case TokenId::Multiply:
                case TokenId::Divide:
                case TokenId::Power:
                    need_oper = false;
                if (stackOfExpr.empty()) {
                    stackOfExpr.push(tokenHelper);
                    break;
                }
                while (stackOfExpr.top().id != TokenId::LParen &&
                       (stackOfExpr.top().op_precedence() > tokenHelper.op_precedence() ||
                        (stackOfExpr.top().op_precedence() == tokenHelper.op_precedence() &&
                         tokenHelper.associativity() == Associativity::Left
                        )
                       )) {
                    if (stackOfExpr.top().identifier == "sin"
                        ||
                        stackOfExpr.top().identifier == "cos"
                        ||
                        stackOfExpr.top().identifier == "log") {
                        if (output.empty()) throw parse_error("not enough numbers to apply function");
                        x = output.back();
                        output.pop_back();
                        if (stackOfExpr.top().identifier == "sin") output.push_back(sin(x));
                        if (stackOfExpr.top().identifier == "cos") output.push_back(cos(x));
                        if (stackOfExpr.top().identifier == "log") output.push_back(log(x));
                        stackOfExpr.pop();
                    }
                    if (stackOfExpr.top().id == TokenId::Plus) {
                        if (output.size() < 2) throw parse_error("not enough numbers");
                        x = output.back();
                        output.pop_back();
                        y = output.back();
                        output.pop_back();
                        output.push_back(y + x);
                        stackOfExpr.pop();
                        if (stackOfExpr.empty()) break;
                    }
                    if (stackOfExpr.top().id == TokenId::Minus) {
                        if (output.size() < 2) throw parse_error("not enough numbers");
                        x = output.back();
                        output.pop_back();
                        y = output.back();
                        output.pop_back();
                        output.push_back(y - x);
                        stackOfExpr.pop();
                        if (stackOfExpr.empty()) break;
                    }
                    if (stackOfExpr.top().id == TokenId::Multiply) {
                        if (output.size() < 2) throw parse_error("not enough numbers");
                        x = output.back();
                        output.pop_back();
                        y = output.back();
                        output.pop_back();
                        output.push_back(y * x);
                        stackOfExpr.pop();
                        if (stackOfExpr.empty()) break;
                    }
                    if (stackOfExpr.top().id == TokenId::Divide) {
                        if (output.size() < 2) throw parse_error("not enough numbers");
                        x = output.back();
                        output.pop_back();
                        y = output.back();
                        output.pop_back();
                        output.push_back(y / x);
                        stackOfExpr.pop();
                        if (stackOfExpr.empty()) break;
                    }
                    if (stackOfExpr.top().id == TokenId::Power) {
                        if (output.size() < 2) throw parse_error("not enough numbers");
                        x = output.back();
                        output.pop_back();
                        y = output.back();
                        output.pop_back();
                        output.push_back(pow(y, x));
                        stackOfExpr.pop();
                        if (stackOfExpr.empty()) break;
                    }
                }
                stackOfExpr.push(tokenHelper);
            }
        }
        prevToken = tokenHelper.id;
        if (tokenHelper.id == TokenId::End) break;
    }

    return output.

            front();

}

bool operator==(const expr &a, const expr &b) {
    return a->equals(b->shared_from_this().operator*());
}

std::ostream &operator<<(std::ostream &os, const expr &e) {
    e->write(os, expr::WriteFormat::Prefix);
    return os;
}

std::ostream &operator<<(std::ostream &os, const fmt_expr &f) {
    f.e->write(os, f.fmt);
    return os;
}

expr operator+(expr a, expr b) {
    return std::make_shared<exprs::operator_plus>(exprs::operator_plus(std::move(a), std::move(b)));
}

expr operator-(expr a, expr b) {
    return std::make_shared<exprs::operator_minus>(exprs::operator_minus(std::move(a), std::move(b)));
}

expr operator*(expr a, expr b) {
    return std::make_shared<exprs::operator_multiply>(exprs::operator_multiply(std::move(a), std::move(b)));
}

expr operator/(expr a, expr b) {
    return std::make_shared<exprs::operator_divide>(exprs::operator_divide(std::move(a), std::move(b)));
}

expr pow(expr m, expr e) {
    return std::make_shared<exprs::operator_pow>(exprs::operator_pow(std::move(m), std::move(e)));
}

expr sin(expr e) {
    return std::make_shared<exprs::operator_sinus>(exprs::operator_sinus(std::move(e)));
}

expr cos(expr e) {
    return std::make_shared<exprs::operator_cosinus>(exprs::operator_cosinus(std::move(e)));
}

expr log(expr e) {
    return std::make_shared<exprs::operator_log>(exprs::operator_log(std::move(e)));
}


