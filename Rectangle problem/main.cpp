#include <iostream>
#include <set>
using namespace std;

int main()
{
	int nr;
	double x, y, xa, ya, xb, yb;
	int nr_rect = 0;
	multiset<pair<double, double>> points;

	cout << "Dati numarul de puncte: ";
	cin >> nr;
	cout << "Introduceti pe cate o linie, separate prin spatiu, valorile corespunzatoare\n\tabscisei x si ordonatei y:\n";
	for (int i = 0; i < nr; i++)
	{
		cin >> x >> y;
		points.insert(make_pair(x, y));
	}
	cout << endl;

	//iteram prin toate punctele
	for (auto it1 = points.begin(); it1 != points.end(); ++it1)
	{
		xa = it1->first;
		ya = it1->second;

		//iteram prin punctele care au abscisa si ordonata mai mari decat ale celui deja fixat
		for (auto it2 = points.upper_bound(make_pair(xa, ya)); it2 != points.end(); ++it2)
			if (it2->first > xa && it2->second > ya)	//verificam daca ar putea fi "colt"
			{
				xb = it2->first;
				yb = it2->second;

				auto it3 = points.find(std::make_pair(xb, ya));
				if (it3 != points.end())	//verificam daca exista un al treilea "colt"
				{
					auto it4 = points.find(std::make_pair(xa, yb));
					if (it4 != points.end()) nr_rect++;	//daca exista si al patrulea "colt", avem un dreptunghi
				}
			}
	}

	cout << "Numarul de dreptunghiuri care se pot forma cu punctele date este: ";
	cout << nr_rect << endl;
}