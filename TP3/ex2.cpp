#include <iostream>
#include <cmath>

using namespace std;

class Cercle
{

    double rayon;
    double x, y;

public:

    Cercle(double r, double cx, double cy)
    {
        rayon = r;
        x = cx;
        y = cy;
    }


    double getRayon()
    {
        return rayon;
    }


    void setRayon(double r)
    {
        rayon = r;
    }

    void getCentre(double &cx, double &cy)
    {
        cx = x;
        cy = y;
    }


    void translate(double dx, double dy)
    {
        x += dx;
        y += dy;
    }


    double surface()
    {
        return M_PI * rayon * rayon;
    }


    double perimetre()
    {
        return 2 * M_PI * rayon;
    }


    bool estEgal(Cercle &a)
    {
        return (rayon == a.rayon) && (x == a.x) && (y == a.y);
    }

    bool appartient(double px, double py)
    {
        double distance = sqrt((px - x) * (px - x) + (py - y) * (py - y));
        return distance <= rayon;
    }

    void affiche()
    {
        cout << "Cercle de rayon " << rayon << " et de centre (" << x << ", " << y << ")" << endl;
    }
};

int main()
{

    Cercle c1(1, 10, 10);
    c1.affiche();


    cout << "Perimetre : " << c1.perimetre() << endl;
    cout << "Surface : " << c1.surface() << endl;


    c1.setRayon(2);
    c1.affiche();


    cout << "Nouveau perimetre : " << c1.perimetre() << endl;
    cout << "Nouvelle surface : " << c1.surface() << endl;

    c1.translate(-10, -10);
    c1.affiche();

    if (c1.appartient(1, 1)) cout << "Le point (1,1) appartient au cercle.\n";
    else cout << "Le point (1,1) n'appartient pas au cercle.\n";

    if (c1.appartient(3, 3)) cout << "Le point (3,3) appartient au cercle.\n";
    else cout << "Le point (3,3) n'appartient pas au cercle.\n";

    Cercle c2(2, 0, 0);
    if (c1.estEgal(c2)) cout << "Les cercles c1 et c2 sont egaux.\n";
    else cout << "Les cercles c1 et c2 sont differents.\n";


    return 0;
}
