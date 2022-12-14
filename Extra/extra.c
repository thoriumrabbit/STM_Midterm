#include <stdio.h>
#include <string.h>


char* unitof10pow3(int i){
    switch (i){
    case -3:
        return " nano";
        break;
    case -2:
        return " micro";
        break;
    case -1:
        return " mili";
        break;
    case 0:
        return " ";
        break;
    case 1:
        return " Kilo";
        break;
    case 2:
        return " Mega";
        break;
    case 3:
        return " Giga";
        break;
    }
}
void suffixWithUnit(double number){
    double natural_part = number;
    int i = 0;
    if (number == 0);
    else if (number > 1000) {
        while(natural_part > 1 && i < 3){
            natural_part = natural_part / 1000;
            if (natural_part < 1) {
                natural_part *= 1000;
                break;
            }
            i++;
        }
    }
    else if (number < 1) {
        while (natural_part < 1 && i > -3){
            natural_part = natural_part * 1000;
            if (natural_part > 100){
                natural_part /= 1000;
                break;
            }
            i--;
        }
    }
    printf("%.4f%s\n",natural_part, unitof10pow3(i));
}

int main()
{
    suffixWithUnit(0.00000000032);
    suffixWithUnit(0.0000062);
    suffixWithUnit(0.000000032);
    suffixWithUnit(0.002);
    suffixWithUnit(152423);
    return 0;
}


