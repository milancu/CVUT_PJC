#pragma once

#include <random>
#include <memory>
#include "helpers.hpp"

class numbers_generator {
public:
    /**
     * Vygeneruje náhodné číslo v intervalu [0, 1)
     */
    virtual double random_double() = 0;

    /**
     * Vygeneruje náhodné celé číslo v intervalu [lower, upper]
     */
    virtual int random_int(int lower, int upper) = 0;

    /**
     * Vygeneruje náhodnou pravdivostní hodnotu (true/false)
     */
    virtual bool random_bool() = 0;

    virtual ~numbers_generator() = default;

    std::unique_ptr<numbers_generator> clone() const;

private:
    virtual numbers_generator *clone1() const = 0;
};

class fixed_generator : public numbers_generator {
public:
    fixed_generator() = default;

    ~fixed_generator() override = default;

    double random_double() override {
        return 0;
    }

    int random_int(int lower, int upper) override {
        return (upper - lower) / 2 + lower;
    }

    bool random_bool() override {
        return true;
    }


    std::unique_ptr<fixed_generator> clone() const;

    fixed_generator *clone1() const override {
        return new fixed_generator(*this);
    }


};

class mersenne_twister_generator : public numbers_generator {
public:
    mersenne_twister_generator(size_t seed);

    double random_double() override;

    int random_int(int lower, int upper) override;

    bool random_bool() override;

    ~mersenne_twister_generator() override = default;


    std::unique_ptr<mersenne_twister_generator> clone() const;

    mersenne_twister_generator *clone1() const override {
        return new mersenne_twister_generator(*this);
    }


private:
    uniform_real_distribution double_dist = uniform_real_distribution{0, 1};
    bernoulli_distribution bool_dist = bernoulli_distribution{0.5};
    std::mt19937_64 rng;
};

class minstd_generator : public numbers_generator {
public:
    minstd_generator(size_t seed);

    double random_double() override;

    int random_int(int lower, int upper) override;

    bool random_bool() override;


    std::unique_ptr<minstd_generator> clone() const;

    minstd_generator *clone1() const override {
        return new minstd_generator(*this);
    }

private:
    uniform_real_distribution double_dist = uniform_real_distribution{0, 1};
    std::bernoulli_distribution bool_dist = std::bernoulli_distribution{0.5};
    std::minstd_rand rng;
};
