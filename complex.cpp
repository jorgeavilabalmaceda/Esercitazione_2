#include <iostream>
#include "complex.hpp"

int main(void) {
	using com = Complex<double>;
	com c1(1.0, 2.0);
	com c2(3.0, -4.0);
	
	
	std::cout << "c1 è: " << c1 << std::endl;
	std::cout << "c2 è: " << c2 << std::endl;
	
	
	com c7=coniugato(c1);
	std::cout<<"il coniugato di c1 è "<<c7<<std::endl;
	
	c7=coniugato(c2); //that way we don't waste memory on another variable c8
	std::cout<<"il coniugato di c2 è "<<c7<<std::endl;
	
	
	
	double d1=0.33;
	
		
	com c11= c1+d1;
	std::cout<<"+ di c1 con reale d1=0.33 è "<<c11<<std::endl;

	
	c1+=d1;
	std::cout<<"+= di c1 con reale d1=0.33 è "<<c1<<std::endl;
	
	com c3=c1+c2;
	std::cout<<"c1+c2 è "<<c3<<std::endl;
	
	c1+=c2;
	std::cout<<"c1+=c2 "<<c1<<std::endl;
	
	
	
	
	com c4(1.0,1.0);
	com c5(2.0,-3.0);
	
	std::cout << "c4 è: " << c4 << std::endl;
	std::cout << "c5 è: " << c5 << std::endl;
	
	com c6=c4*c5;
	std::cout<<"c4*c5= "<<c6<<std::endl;
	
	c4*=c5;
	std::cout<<"c4*=c5 è "<<c4<<std::endl;
	
	
	
	// moltiplicazione con double

	double d2=0.5;
	com c9(3.0,-2.0);
	com c10=c9*d2;
	std::cout<<"c9=3-2i per d2=0.5 è "<<c10<<std::endl;
	
	c9*=d2;
	std::cout<<"c9*=d2 è "<<c9<<std::endl;
	

	return 0;
}