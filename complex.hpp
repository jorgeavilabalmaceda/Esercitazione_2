#pragma once

template<typename T> requires std::floating_point<T>
class Complex
{
	T reale, immaginaria;
	
public:
	/* default constructor*/
	Complex()
		: reale(0), immaginaria(0) //as to initialize 
	{}
	
	/* costruttore di conversione*/
	explicit Complex(T r)
        : reale(r), immaginaria(0)
    {
        std::cout << "converting constructor called" << std::endl;
    }
	
	/* user-defined constructor*/
	Complex(T r, T c)
        : reale(r), immaginaria(c)
    {}
	
	/* queste servono per non modificare le parti quando vengono chiamate*/
	T ParteReale(void) const {
		return reale;
	}
	
	T ParteImmaginaria(void) const {
		return immaginaria;
	}
	
	/*definisco l'operatore += */
	Complex& operator+=(const Complex& other) {
        T a = reale;
        T b = immaginaria;
        T c = other.reale;
        T d = other.immaginaria;
        reale = a + c;
        immaginaria = b + d;
        return *this;
	}
	
	/*operazione += tra complesso e intero */ 
	Complex& operator+=(const T& other) {
		reale += other;
		return *this;
	}
	
	
		/* overload dell'operatore + */
		Complex operator+(const Complex& other) const {
		Complex cn = *this;
		cn += other;
		return cn;
		}
	
	/*operazione + tra complesso e intero*/
	Complex operator+(const T& other) {
		Complex cn = *this;
		cn +=other;
		return cn;
	}
	
	/* definisco l'operatore *= */	
	Complex& operator*=(const Complex& other) {
		T a = reale;
		T b = immaginaria;
		T c = other.reale;
		T d = other.immaginaria;
		reale = a*c - b*d;
		immaginaria = a*d + c*b;
		return *this;
	}
	
	/*operazione *= tra complesso e intero */
	Complex& operator*=(const T& other) {
        reale *= other;
		immaginaria *= other;
        return *this;
	}
		/* overload dell'operatore '*' */
		Complex operator*(const Complex& other) const { //OJO: avevamo fatto lo stesso errore di sopra//
		Complex cn = *this;
		cn *= other;
		return cn;
		}
	
	/*operazione * tra complesso e double*/
	Complex operator*(const T& other) {
		Complex cn = *this;
		cn *= other;
		return cn;
	}
};

/* funzione << per stampare i complessi*/
template<typename T>
std::ostream&
operator<<(std::ostream& os, const Complex<T>& r) {
    if (r.ParteImmaginaria() != 0) {
		if (r.ParteImmaginaria()<0) {
			T tmp = -r.ParteImmaginaria();
			os << r.ParteReale() << "-" << tmp << "i";
		}
		else 
			os << r.ParteReale() << "+" << r.ParteImmaginaria() << "i";
	}
    else
		os << r.ParteReale(); 

    return os;
}

/* funzione che mi stampa il coniugato */
template<typename T>
Complex<T> coniugato(const Complex<T>& r) {
	return Complex<T>(r.ParteReale(), -r.ParteImmaginaria());
}

/* proprietà commutativa dell'operazione + con intero */
template<typename T>
Complex<T>
operator+(const T& i, const Complex<T>& r)
{
    return r + i;
}

/* proprietà commutativa dell'operazione * con intero */
template<typename T>
Complex<T>
operator*(const T& i, const Complex<T>& r)
{
    return r * i;
}
