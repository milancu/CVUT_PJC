#pragma once

#include <memory>
#include <algorithm>

enum class generator_kind {
    random,
    mersenne,
    minstd
};


class numbers_generator {
public:
    int counter = 0;
    int falseCounter = 0;
    int min = std::numeric_limits<int>::max();
    int max = - (std::numeric_limits<int>::infinity());
    int counterInt = 0;
    double minD = std::numeric_limits<double>::max();
    double maxD = - (std::numeric_limits<double>::infinity());
    int counterDouble = 0;


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

    static std::unique_ptr<numbers_generator> create_by_kind(generator_kind kind, size_t seed);

    double min_generated_double() { return minD; }

    double max_generated_double() { return maxD; }

    size_t doubles_generated() { return counterDouble; }

    int min_generated_int() { return min; }

    int max_generated_int() { return max; }

    size_t ints_generated() { return counterInt; }

    size_t trues_generated() { return counter - falseCounter; }

    size_t falses_generated() { return falseCounter; }

    size_t bools_generated() { return counter; }
};


