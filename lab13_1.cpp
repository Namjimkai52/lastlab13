#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}
void stat(const double arr[], int n, double result[]) {
    double sum = 0, sumSq = 0, product = 1, harmonicSum = 0;
    double maxVal = arr[0], minVal = arr[0];

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        sumSq += arr[i] * arr[i];
        product *= arr[i];
        harmonicSum += 1.0 / arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
        if (arr[i] < minVal) minVal = arr[i];
    }

    result[0] = sum / n; 
    result[1] = sqrt((sumSq / n) - (result[0] * result[0])); 
    result[2] = (product > 0) ? pow(product, 1.0 / n) : 0; 
    result[3] = (harmonicSum > 0) ? n / harmonicSum : 0; 
    result[4] = maxVal; 
    result[5] = minVal; 
}