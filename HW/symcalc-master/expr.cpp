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
    return std::make_shared<exprs::variable>(exprs::variable(name));
}

expr create_expression_tree(const std::string &expression) {
    std::deque<expr> output = std::deque<expr>();
    std::stack<Token> stackOfExpr = std::stack<Token>();
    std::istringstream is(expression);
    Tokenizer tokenizer = Tokenizer(is);
//    TokenId prevToken;

    while (true) {
        Token tokenHelper = tokenizer.next();
        switch (tokenHelper.id) {
            case TokenId::End:
                while (!stackOfExpr.empty() && stackOfExpr.top().id != TokenId::LParen) {
//                    output.push_back(expr::variable(stackOfExpr.top().identifier));
                    if (stackOfExpr.top().id == TokenId::Plus) {
                        expr x = output.back();
                        output.pop_back();
                        expr y = output.back();
                        output.pop_back();
                        output.push_back(y + x);
                        stackOfExpr.pop();
                        if (stackOfExpr.empty()) break;
                    }
                    if (stackOfExpr.top().id == TokenId::Minus) {
                        expr x = output.back();
                        output.pop_back();
                        expr y = output.back();
                        output.pop_back();
                        output.push_back(y - x);
                        stackOfExpr.pop();
                        if (stackOfExpr.empty()) break;
                    }
                    if (stackOfExpr.top().id == TokenId::Multiply) {
                        expr x = output.back();
                        output.pop_back();
                        expr y = output.back();
                        output.pop_back();
                        output.push_back(y * x);
                        stackOfExpr.pop();
                        if (stackOfExpr.empty()) break;
                    }
                    if (stackOfExpr.top().id == TokenId::Divide) {
                        expr x = output.back();
                        output.pop_back();
                        expr y = output.back();
                        output.pop_back();
                        output.push_back(y / x);
                        stackOfExpr.pop();
                        if (stackOfExpr.empty()) break;
                    }
                    if (stackOfExpr.top().id == TokenId::Power) {
                        expr x = output.back();
                        output.pop_back();
                        expr y = output.back();
                        output.pop_back();
                        output.push_back(pow(y, x));
                        stackOfExpr.pop();
                        if (stackOfExpr.empty()) break;
                    }
                }
                break;
            case TokenId::Number:
                output.push_back(expr::number(tokenHelper.number));
                break;
            case TokenId::Identifier:
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
                stackOfExpr.push(tokenHelper);
                break;
            case TokenId::RParen:
                while (stackOfExpr.top().id != TokenId::LParen) {
                    if (!stackOfExpr.empty()) {
                        if (stackOfExpr.empty()) break;
                        if (stackOfExpr.top().id == TokenId::Plus) {
                            expr x = output.back();
                            output.pop_back();
                            expr y = output.back();
                            output.pop_back();
                            output.push_back(y + x);
                            stackOfExpr.pop();
                            if (stackOfExpr.empty()) break;
                        }
                        if (stackOfExpr.top().id == TokenId::Minus) {
                            expr x = output.back();
                            output.pop_back();
                            expr y = output.back();
                            output.pop_back();
                            output.push_back(y - x);
                            stackOfExpr.pop();
                            if (stackOfExpr.empty()) break;
                        }
                        if (stackOfExpr.top().id == TokenId::Multiply) {
                            expr x = output.back();
                            output.pop_back();
                            expr y = output.back();
                            output.pop_back();
                            output.push_back(y * x);
                            stackOfExpr.pop();
                            if (stackOfExpr.empty()) break;
                        }
                        if (stackOfExpr.top().id == TokenId::Divide) {
                            expr x = output.back();
                            output.pop_back();
                            expr y = output.back();
                            output.pop_back();
                            output.push_back(y / x);
                            stackOfExpr.pop();
                            if (stackOfExpr.empty()) break;
                        }
                        if (stackOfExpr.top().id == TokenId::Power) {
                            expr x = output.back();
                            output.pop_back();
                            expr y = output.back();
                            output.pop_back();
                            output.push_back(pow(y, x));
                            stackOfExpr.pop();
                            if (stackOfExpr.empty()) break;
                        }
                    }
                }
                if (stackOfExpr.empty()) break;

                if (stackOfExpr.top().id == TokenId::LParen) {
                    stackOfExpr.pop();
                }
                if (stackOfExpr.empty()) break;
                if (stackOfExpr.top().identifier == "sin"
                    ||
                    stackOfExpr.top().identifier == "cos"
                    ||
                    stackOfExpr.top().identifier == "log") {
                    expr x = output.back();
                    output.pop_back();
                    if (stackOfExpr.top().identifier == "sin") output.push_back(sin(x));
                    if (stackOfExpr.top().identifier == "cos") output.push_back(cos(x));
                    if (stackOfExpr.top().identifier == "log") output.push_back(log(x));
                    stackOfExpr.pop();
                }
                if (stackOfExpr.empty()) break;
                if (stackOfExpr.top().id == TokenId::Plus) {
                    expr x = output.back();
                    output.pop_back();
                    expr y = output.back();
                    output.pop_back();
                    output.push_back(y + x);
                    stackOfExpr.pop();
                    if (stackOfExpr.empty()) break;
                }
                if (stackOfExpr.top().id == TokenId::Minus) {
                    expr x = output.back();
                    output.pop_back();
                    expr y = output.back();
                    output.pop_back();
                    output.push_back(y - x);
                    stackOfExpr.pop();
                    if (stackOfExpr.empty()) break;
                }
                if (stackOfExpr.top().id == TokenId::Multiply) {
                    expr x = output.back();
                    output.pop_back();
                    expr y = output.back();
                    output.pop_back();
                    output.push_back(y * x);
                    stackOfExpr.pop();
                    if (stackOfExpr.empty()) break;
                }
                if (stackOfExpr.top().id == TokenId::Divide) {
                    expr x = output.back();
                    output.pop_back();
                    expr y = output.back();
                    output.pop_back();
                    output.push_back(y / x);
                    stackOfExpr.pop();
                    if (stackOfExpr.empty()) break;
                }
                if (stackOfExpr.top().id == TokenId::Power) {
                    expr x = output.back();
                    output.pop_back();
                    expr y = output.back();
                    output.pop_back();
                    output.push_back(pow(y, x));
                    stackOfExpr.pop();
                    if (stackOfExpr.empty()) break;
                }
                break;
            case TokenId::Plus:
            case TokenId::Minus:
            case TokenId::Multiply:
            case TokenId::Divide:
            case TokenId::Power:
                if (stackOfExpr.empty()) {
                    stackOfExpr.push(tokenHelper);
                    break;
                }
                while (true) {
                    if ((!stackOfExpr.empty()) && stackOfExpr.top().id != TokenId::LParen &&
                        stackOfExpr.top().id != TokenId::RParen) {
                        if ((tokenHelper.associativity() == Associativity::Left &&
                             tokenHelper.op_precedence() <= stackOfExpr.top().op_precedence()) ||
                            (tokenHelper.associativity() == Associativity::Right &&
                             tokenHelper.op_precedence() < stackOfExpr.top().op_precedence())
                                ) {
                            if (stackOfExpr.top().id == TokenId::Plus) {
                                expr x = output.back();
                                output.pop_back();
                                expr y = output.back();
                                output.pop_back();
                                output.push_back(y + x);
                                stackOfExpr.pop();
                                if (stackOfExpr.empty()) break;
                            }
                            if (stackOfExpr.top().id == TokenId::Minus) {
                                expr x = output.back();
                                output.pop_back();
                                expr y = output.back();
                                output.pop_back();
                                output.push_back(y - x);
                                stackOfExpr.pop();
                                if (stackOfExpr.empty()) break;
                            }
                            if (stackOfExpr.top().id == TokenId::Multiply) {
                                expr x = output.back();
                                output.pop_back();
                                expr y = output.back();
                                output.pop_back();
                                output.push_back(y * x);
                                stackOfExpr.pop();
                                if (stackOfExpr.empty()) break;
                            }
                            if (stackOfExpr.top().id == TokenId::Divide) {
                                expr x = output.back();
                                output.pop_back();
                                expr y = output.back();
                                output.pop_back();
                                output.push_back(y / x);
                                stackOfExpr.pop();
                                if (stackOfExpr.empty()) break;
                            }
                            if (stackOfExpr.top().id == TokenId::Power) {
                                expr x = output.back();
                                output.pop_back();
                                expr y = output.back();
                                output.pop_back();
                                output.push_back(pow(y, x));
                                stackOfExpr.pop();
                                if (stackOfExpr.empty()) break;
                            }
                            break;
                        } else {
                            break;
                        }
                    } else {
                        break;
                    }
                }
                stackOfExpr.push(tokenHelper);
                break;


        }
//        prevToken = tokenHelper.id;
        if (tokenHelper.id == TokenId::End) break;
    }
    return output.front();
}

bool operator==(const expr &a, const expr &b) {
    return a->equals(b->shared_from_this().operator*());
}

std::ostream &operator<<(std::ostream &os, const expr &e) {
    e->write(os, expr::WriteFormat::Prefix);
    return os;
}

std::ostream &operator<<(std::ostream &os, const fmt_expr &e) {
    e.e->write(os, e.fmt);
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
