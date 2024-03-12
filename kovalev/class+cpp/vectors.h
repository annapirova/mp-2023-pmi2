#ifndef vectors_H
#define vectors_H
class vector
{
    private:
    int size;
    double* vec;
    public:
    vector();
    vector(int size_);
    ~vector();
    vector operator + (const vector &B);
    vector& operator = (const vector &B);
    double& operator [] (const int i);
    void set_random_vec(double a, double b);
    void set_vector_size(int size_);
    void  Print();
    void set_some_vec();
};











#endif