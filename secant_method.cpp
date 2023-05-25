#include <iostream>
#include <cmath>
#include <iomanip>


// structure for secant method 
struct SC_method {

        // constructor
        SC_method(double x0_in, double x1_in, double precision_in, int max_iterations_in){

                x0 = x0_in;
                x1 = x1_in;
                precision = precision_in;
                max_iterations = max_iterations_in;
        }

        // define your function here
        double fx(double x){
                return x * x - 5;
        }

        // call secant method
        double estimate_root(){

                iterator = 0;
                while((iterator < max_iterations) && ((std::abs(x1 - x0)>precision))) {

                        answer = x1 - (fx(x1) * (x1 - x0)) / (fx(x1) - fx(x0));

                        x0 = x1;
                        x1 = answer;
                        iterator++;
                } 

                if(iterator > max_iterations){
                    std::cout << "root not found." << '\n';
                    return std::numeric_limits<double>::quiet_NaN();
                }

                return answer;
        }

        // getter - print answer
        void print_answer(){
                std::cout << " Secant method called... " << '\n';
                std::cout << " root = " << answer << '\n';
                std::cout << " f(x) = " << std::setprecision(16) << fx(answer) << '\n';
                std::cout << " iterations = " << iterator << '\n';
                std::cout << " precision = " << std::setprecision(16) << precision << '\n';
        }

        ~SC_method() = default;

protected:
        double x0{}, x1{}, answer{}, precision{};
        int max_iterations{}, iterator{};
}; // SC_method





// main 
int main(){

        // define two points to draw secant, precision, and max iterations 
        double x0 = 1;
        double x1 = 2;
        double precision = 0.0001;
        int max_iterations = 100;

        // create instance of secant method structure 
        SC_method find_root_1 = SC_method(x0, x1, precision, max_iterations);

        // call methods 
        find_root_1.estimate_root();
        find_root_1.print_answer();


        std::cout << "done." << "\n";
        return 0;
}




