#include <iostream>
#include <cmath>
#include <iomanip>





// structure for iterative-bisection method
struct IB_method {

        // constructor
        IB_method(double lower_bound_in, double upper_bound_in, double precision_in, int max_iterations_in){

                lower_bound = lower_bound_in;
                upper_bound = upper_bound_in;
                precision = precision_in;
                max_iterations = max_iterations_in;

        }

        // define your function here
        double fx(double x_input){
                return x_input*x_input - 5;
        }

        // call bisection method
        double estimate_root(){

                // calculate fx given upper and lower bounds
                fx_lower = fx(lower_bound);
                fx_upper = fx(upper_bound);


                if(fx_lower*fx_upper >= 0) {
                        std::cout << "Change in sign not present for current bounds - bisection methods not applied" << '\n';
                        return std::numeric_limits<double>::quiet_NaN();
                }


                current_iterator = 0;
                fx_current = fx(answer);

                while((current_iterator < max_iterations) && (std::abs(fx_current)>precision)) {

                        // get midpoint and fx values
                        answer = (lower_bound + upper_bound)/2;
                        fx_current = fx(answer);

                        // change in sign - therefore root is between lower bound and midpoint
                        // else the root is between the midpoint and upper bound
                        if(fx_lower*fx_current < 0) {

                                upper_bound = answer;
                                fx_upper = fx_current;
                        }
                        else{
                                lower_bound = answer;
                                fx_lower = fx_current;
                        }

                        current_iterator++;
                } // while

                if(current_iterator > max_iterations){
                    std::cout << "root not found." << '\n';
                    return std::numeric_limits<double>::quiet_NaN();
                }

                return answer;
        }

        // getter - print answer
        void print_answer(){

                std::cout << " Iterative-bisection method called... " << '\n';
                std::cout << " root = " << answer << '\n';
                std::cout << " f(x) = " << std::setprecision(16) << fx(answer) << '\n';
                std::cout << " iterations = " << current_iterator << '\n';
                std::cout << " precision = " << std::setprecision(16) << precision << '\n';
        }

        ~IB_method() = default;

protected:
        double lower_bound{}, upper_bound{}, precision{}, fx_lower{}, fx_upper{}, answer{}, fx_current{};
        int max_iterations{}, current_iterator{};
}; // IB_method





// main
int main(){

        // define lower and upper bounds, precision, and max iterations
        double lower_bound = 1.0;
        double upper_bound = 3.0;
        double precision = 0.0001;
        int max_iterations = 100;

        // create instance of iterative bisection strucure
        IB_method find_root_1 = IB_method(lower_bound, upper_bound, precision, max_iterations);

        // call methods
        find_root_1.estimate_root();
        find_root_1.print_answer();


        std::cout << "done." << '\n';
        return 0;
}
