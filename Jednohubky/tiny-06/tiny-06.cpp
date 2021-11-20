#include "tiny-06.hpp"

#include <random>
#include <cstdint>

// Let's hope your std::random_device is implemented well.
// !! don't use as actual CSPRNG !!
class random_generator : public numbers_generator {
public:
    random_generator() = default;

    double random_double() override {
        double value = double_dist(rdev);
        if (value < minD) { minD = value; };
        if (value > maxD) { maxD = value; };
        counterDouble++;
        return value;
    }

    int random_int(int lower, int upper) override {
        counterInt++;
        int value = std::uniform_int_distribution<int>(lower, upper)(rdev);
        if (value > max) { max = value; };
        if (value < min) { min = value; };
        return value;
    }

    bool random_bool() override {
        counter++;
        bool result = bool_dist(rdev);
        if (result == false) {
            falseCounter++;
        }
        return result;
    }

    ~random_generator() override = default;

private:
    std::uniform_real_distribution<double> double_dist { 0, 1 };
    std::bernoulli_distribution bool_dist { 0.5 };
    std::random_device rdev;
};

class mersenne_twister_generator : public numbers_generator {
public:
    mersenne_twister_generator(size_t seed) :
            rng(seed)
    {}

    double random_double() override {
        double value = double_dist(rng);
        if (value < minD) { minD = value; };
        if (value > maxD) { maxD = value; };
        counterDouble++;
        return value;
    }

    int random_int(int lower, int upper) override {
        counterInt++;
        int value = std::uniform_int_distribution<int>(lower, upper)(rng);
        if (value > max) { max = value; };
        if (value < min) { min = value; };
        return value;
    }

    bool random_bool() override {
        counter++;
        bool result = bool_dist(rng);
        if (result == false) {
            falseCounter++;
        }
        return result;
    }

    ~mersenne_twister_generator() override = default;
private:
    std::uniform_real_distribution<double> double_dist { 0, 1 };
    std::bernoulli_distribution bool_dist { 0.5 };
    std::mt19937_64 rng;
};

class minstd_generator : public numbers_generator {
public:
    minstd_generator(size_t seed) :
            rng(static_cast<uint32_t>(seed)) {}

    double random_double() override {
        double value = double_dist(rng);
        if (value < minD) { minD = value; };
        if (value > maxD) { maxD = value; };
        counterDouble++;
        return value;
    }

    int random_int(int lower, int upper) override {
        counterInt++;
        int value = std::uniform_int_distribution<int>(lower, upper)(rng);
        if (value > max) { max = value; };
        if (value < min) { min = value; };
        return value;
    }

    bool random_bool() override {
        counter++;
        bool result = bool_dist(rng);
        if (result == false) {
            falseCounter++;
        }
        return result;
    }
private:
    std::uniform_real_distribution<double> double_dist { 0, 1 };
    std::bernoulli_distribution bool_dist { 0.5 };
    std::minstd_rand rng;
};

std::unique_ptr<numbers_generator> numbers_generator::create_by_kind(generator_kind kind, size_t seed) {
    switch (kind) {
        case generator_kind::random:
            return std::make_unique<random_generator>();
        case generator_kind::mersenne:
            return std::make_unique<mersenne_twister_generator>(seed);
        case generator_kind::minstd:
            return std::make_unique<minstd_generator>(seed);
        default:
            throw std::invalid_argument("Asked for unknown kind of generator!");
    }
}
