#include "tiny-05.hpp"

namespace pjc {

    complex::complex(double real, double imaginary) :
            m_real(real),
            m_imag(imaginary) {}

    complex complex::operator+(const complex &rhs) const {
        return complex(real() + rhs.real(), imag() + rhs.imag());
    }

    complex complex::operator+(double value) const {
        return complex(real() + value, imag());
    }

    complex complex::operator-(const complex &rhs) const {
        return complex(real() - rhs.real(), imag() - rhs.imag());
    }

    complex complex::operator-(double value) const {
        return complex(real() - value, imag());
    }

    complex complex::operator*(const complex &rhs) const {
        return complex(real() * rhs.real() - imag() * rhs.imag(), real() * rhs.imag() + imag() * rhs.real());
    }

    complex complex::operator*(double value) const {
        return complex(real() * value, imag() * value);
    }

    double complex::real() const {
        return m_real;
    }

    void complex::real(double d) {
        m_real = d;
    }

    double complex::imag() const {
        return m_imag;
    }

    void complex::imag(double d) {
        m_imag = d;
    }

}
