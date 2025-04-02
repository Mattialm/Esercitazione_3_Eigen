#include<iostream>
#include<iomanip>
#include "Eigen/Eigen"

using namespace Eigen;
using namespace std;


void solverr(Matrix2d A, Vector2d b)
{
    Vector2d x_e;
    x_e << -1.0, -1.0;

    Vector2d x_palu = A.fullPivLu().solve(b);
    Vector2d x_qr = A.householderQr().solve(b);

    double err_palu = (x_palu - x_e).norm()/x_e.norm();
    double err_qr = (x_qr - x_e).norm()/x_e.norm();

    cout << "La soluzione con PALU al sistema è: " << "[" << scientific << setprecision(16) << x_palu << "]" << endl;
    cout << "La soluzione al sistema con QR del sistema è: " << "[" << x_qr << "]" << endl;
    cout << "Errore relativo palu = " << err_palu << endl;
    cout << "Errore relativo qr: " << err_qr << "\n" << endl;

}


int main()
{

    Matrix2d A_1;
    A_1 << 5.547001962252291e-01, -3.770900990025203e-02, 
            8.320502943378437e-01, -9.992887623566787e-01;
    Vector2d b_1;
    b_1 << -5.169911863249772e-01, 1.672384680188350e-01;

    cout << "Sistema 1: " << endl;
    solverr(A_1, b_1);


    Matrix2d A_2 ;
    A_2 << 5.547001962252291e-01, -5.540607316466765e-01, 
            8.320502943378437e-01, -8.324762492991313e-01;
    Vector2d b_2 ;
    b_2 << -6.394645785530173e-04, 4.259549612877223e-04;

    cout << "Sistema 2: " << endl;
    solverr(A_2, b_2);
    
    
    Matrix2d A_3;
    A_3 << 5.547001962252291e-01, -5.547001955851905e-01, 
            8.320502943378437e-01, -8.320502947645361e-01;
    Vector2d b_3;
    b_3 << -6.400391328043042e-10, 4.266924591433963e-10;

    cout << "Sistema 3: " << endl;
    solverr(A_3, b_3);


    return 0;
}
