
class Polynomial {
private:
    double* coeff;
    int size;

public:
    Polynomial();
    Polynomial(const double* values, int count);

    //Destructor
    ~Polynomial();                                   
    //Copy Constructor
    Polynomial(const Polynomial& other);              
    //Copy Assignment
    Polynomial& operator=(const Polynomial& other);  
    //Move Constructor
    Polynomial(Polynomial&& other) noexcept;         
    //Move Assignment
    Polynomial& operator=(Polynomial&& other) noexcept; 

    double evaluate(double x) const;
};

