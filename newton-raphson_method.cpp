#include <iostream>
#include <cmath>
#include <iomanip>





// structure for newton-raphson method
struct NR_method {

        // constructor
        NR_method(double initial_guess_in, int max_iterations_in, double precision_in){
                initial_guess = initial_guess_in;
                precision = precision_in;
                max_iterations = max_iterations_in;
        }

        // define function here
        double fx(double x){
                return x*x - 5;
        }

        // define derivative here
        double dfdx(double x){
                return 2*x;
        }

        // call newton-raphon function
        double estimate_root(){

                answer = initial_guess;
                while((iterator<max_iterations) && (std::abs(fx(answer))>precision)) {

                        // update x
                        answer = answer - fx(answer)/dfdx(answer);
                        iterator++;
                }

                if(iterator > max_iterations) {
                        std::cout << "root not found." << '\n';
                        return std::numeric_limits<double>::quiet_NaN();
                }

                return answer;
        }

        // getter - print answer
        void print_answer(){

                std::cout << " Newton-Raphson method called... " << '\n';
                std::cout << " root = " << answer << '\n';
                std::cout << " f(x) = " << std::setprecision(16) << fx(answer) << '\n';
                std::cout << " iterations = " << iterator << '\n';
                std::cout << " precision = " << std::setprecision(16) << precision << '\n';
        }

        ~NR_method() = default;

protected:
        double initial_guess{}, precision{}, answer{};
        int max_iterations{}, iterator{};
}; // NR_method





// main
int main(){

        // initialise initial guess
        double initial_guess = 1;
        double precision = 0.001;
        int max_iterations = 20;

        // create structure for guess
        NR_method squared_guess = NR_method(initial_guess, max_iterations, precision);

        // make guess
        squared_guess.estimate_root();

        // get answer
        squared_guess.print_answer();


        std::cout << "done." << '\n';
        return 0;
}
