#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector <vector<double>> objects;
    vector <double> list;
    int input = 1;
    int counter = 0;
    double sum = 0.0;
    int c = 3;
    cout << "If you want to end product list, please print 0\n";
    cout << "Write with care. Strichcode, Price, Discount . In that sequence. Do not print equal strichcodes if you dont want to break the machine\n";
    while (input != 0)
    {
        vector <double> sim;
        for (int a = 0; a < c; a++)
        {
            double q = 0;
            cin >> q;
            if (q != 0)
            {
                sim.push_back(q);
            }
            else { a -= 1; cout << "Nope!\n"; }
        }
        objects.push_back(sim);
        cin >> input;
    }
    input = 1;
    cout << "If you want to end shopping, please print 0\n";
    while (input != 0)
    {
        int y = 0;
        cin >> input;
        cout << "\n";
        bool hmm = false;
        bool what = true;
        for (int cai = 0; cai < counter; cai++)
        {
            if (list[cai] == input)
            {
                y = 1;
                break;
            }
        }
        for (int i = 0; i < 10; i++)
        {
            if ((prcodes[i] == input) && (y == 0))
            {
                printf("scanning...\n");
                productlist[counter] = input;
                pricelist[counter] = price[i];
                countlist[counter] = 1;
                discountlist[counter] = discounts[i];
                printf("You added %d to your cheque. Price: %lf . Discount: %lf per cents. \n", input, price[i], discounts[i] * 100);
                hmm = true;
                counter++;
            }
            else
            {
                if (y == 1)
                {
                    for (int o = 0; o < counter; o++)
                    {
                        if (productlist[o] == input)
                        {
                            printf("scanned. You added another %d.", productlist[o]);
                            countlist[o]++;
                            hmm = true;
                            what = false;
                            break;
                        }
                    }
                }
            }
            if (what == false)
            {
                break;
            }
        }
        if (hmm == false)
        {
            cout << "Your product doesnt exist\n";
        }
    }
    cout << "======== YOUR CHEQUE ========\n";
    for (int p = 0; p < counter; p++)
    {
        cout << "======\n";
        printf("%d.\nProduct....%d\nOne cost....%lf\nAmount....%d\nAll cost....%lf\n", p + 1, productlist[p], round(pricelist[p] * (1 - discountlist[p])), countlist[p], round(pricelist[p] * (1 - discountlist[p])) * countlist[p]);
        cout << "======\n";
        sum += round(pricelist[p] * (1 - discountlist[p])) * countlist[p];
    }
    printf("Conclusive summ: %lf\n", sum);
    cout << "Thank you for using our virtual shop.";
}