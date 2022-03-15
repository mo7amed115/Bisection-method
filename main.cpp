#include <iostream>
#include<cmath>
#include <vector>

using namespace std ;

// Function for get the root interval

double P_interval(double , double , double);
double n_interval(double , double , double);
double equation(double , double , double , double) ;
double approx(double , double , double , double , double);

int main()
{
    double result_y[20];
    double x ,y , a , b , m ,n ,o , approximation_value;
    int Choose ;
//
    cout<<"Find the root of equation : "<<endl;
    cout<<"============================"<<endl;
    cout<<"enter first factor: ";
    cin>> m ;
    cout<<"enter secound factor: ";
    cin>> n ;
    cout<<"enter last factor: ";
    cin>> o ;
    cout<<"Please choose the Positive or Negative interval : "<<endl;
    cout<<endl;
    cout<<"1. Positive ."<<endl<<"2. Negative ."<<endl;
    cin>>Choose ;

    if (Choose == 1)
      {
        a = P_interval(m , n ,o);
        b = a + 1 ;
        cout<<"a = "<< a <<endl;
        cout<<"b = "<< b <<endl;
        cout<<"=================="<<endl;
        cout<<"x ∈ [ "<< a << " , " << b << " ]" <<endl;
        cout<<"=================="<<endl;
        approximation_value = approx(m , n , o , a , b) ;
        cout<<"The approximation value = "<< approximation_value <<endl;

      }
    else if (Choose == 2)
      {
          a = - n_interval(m , n , o) ;
          b = a - 1 ;
          cout<<"a = "<< a <<endl;
          cout<<"b = "<< b <<endl;
          cout<<"=================="<<endl;
          cout<<"x ∈ [ "<< a << " , " << b << " ]" <<endl;
          cout<<"=================="<<endl;
          approximation_value = approx(m , n , o , a , b) ;
          cout<<"The approximation value = "<< approximation_value <<endl;

      }
    else
      {
         cout<<"Try again !!"<<endl;
         cin>>Choose ;
      }


}

double P_interval(double m , double n , double o)
{
    double a , b ;
    double result_y[20];
    for(int x = 0 ; x <= 20 ; ++x)
        {   double y ;
            y = equation(m , n , o , x);
            result_y[x] = {y};



            if ((result_y[x] * result_y[x-1]) < 0 )
                {
                    a = x-1 ;
                    b = x ;

                }
        }
return a ;
}

double n_interval(double m , double n , double o)
{
    double result_y[20];
    double a , b ;
    for (int x = 0; x >= -9; --x)
    {
        float y;
        y = (m * (pow(x, 2)) + (n * x) + o);
        result_y[-x] = { y };
    }
    for(int i=0 ; i<=9 ; ++i)
    {
        if ((result_y[i] * result_y[i+1]) < 0)
            {
                a = i;
                b = i+1;
            }
    }
return a ;
}

double equation(double m , double n , double o , double x)
{
    double y;
    y = (m*(pow (x,2))+(n*x) + o);
    return y ;
}

double approx( double m , double n , double o , double a , double b)
{   double c ,app_value;
    double arr_a[20] , arr_b[20] , arr_c[20] ,
    arr_fun_a[20] , arr_fun_b[20] , arr_fun_c[20];

    for (int i = 0 ; i <= 20 ; ++i)
        {
            if (a < b)
                {
                    c = ((a + b)/2);
                    arr_a[i] = {a};
                    arr_b[i] = {b};
                    arr_c[i] = {c};
                    arr_fun_a[i] = equation(m , n , o , a);
                    arr_fun_b[i] = equation(m , n , o , b);
                    arr_fun_c[i] = equation(m , n , o , c);
                    if ( arr_fun_c[i] < 0)
                        {
                            a = c ;
                            b = b ;
                        }
                    else
                        {
                            a = a ;
                            b = c ;
                        }

                }
            else if (b < a)
                {
                    c = ((a + b)/2);
                    arr_a[i] = {a};
                    arr_b[i] = {b};
                    arr_c[i] = {c};
                    arr_fun_a[i] = equation(m , n , o , a);
                    arr_fun_b[i] = equation(m , n , o , b);
                    arr_fun_c[i] = equation(m , n , o , c);
                    if ( arr_fun_c[i] < 0)
                        {
                            a = c ;
                            b = b ;
                        }
                    else
                        {
                            a = a ;
                            b = c ;
                        }
                }
        }
        for (int i = 0 ; i<20 ; ++i)
            {
                double error_value = arr_c[i-1] - arr_c[i] ;

                if ( error_value <= 0.0009)
                        {
                            app_value = arr_c[i-1] ;
                            break ;
                        }
            }
return app_value;
}
