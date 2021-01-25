#include<iostream>
#include<iomanip>

using namespace std;
int pop[11];
int cal_fitness(int val)
{
    return val*val;
}

string to_bin(int a)
{
    string binary = "";
    int mask = 1;
    for(int i = 0; i < 8; i++)
    {
        if((mask&a) >= 1)
            binary = "1"+binary;
        else
            binary = "0"+binary;
        mask<<=1;
    }
    return binary;
}

void crossover(int x,int y, int gen)
{
    int i;
    pop[10] = gen;
    for(i = 0;i<10;i++)
    {
        if(i%2)
            pop[i] = (x+y+i)/2;
        else
            pop[i] = (x+y-i)/2;

    }
}

int main()
{
    int i;
    for(i=0;i<10;i++)
    {
        pop[10] = 0;
        pop[i] = rand()%100;
    }

    int colWidth=20;
    int max1 = 0;
    int max2 = 0,fit,index1,index2;

    cout<<"\t\t\t Generation :  "<<pop[10]<<"\n";
    cout << setfill('*') << setw(3*colWidth) << "*" << endl;
    cout << setfill(' ') << fixed;
    cout << setw(colWidth) <<"Value"<< setw(colWidth) <<" Population" << setw(colWidth) << "Fitness Score" <<endl;
    cout << setfill('*') << setw(3*colWidth) << "*" << endl;
    cout << setfill(' ') << fixed;
    for(i=0;i<10;i++)
    {
        fit = cal_fitness(pop[i]);
        cout << setw(colWidth) << pop[i] << setw(colWidth) << to_bin(pop[i])<< setw(colWidth) <<fit <<  endl;
        if(fit>max2)
        {
            if(fit>max1)
            {
                max2 = max1;
                index2 = index1;
                max1 = fit;
                index1 = i;
                continue;
            }
            max2 = fit;
            index2 = i;
        }
    }

    cout<<"\n\tThe two fittest are : "<<pop[index1]<<" and "<<pop[index2]<<"\n\n\n";

    int gen = 1;
    crossover(pop[index1],pop[index1],gen);

    cout<<"\t\t\t Generation :  "<<pop[10]<<"\n";
    cout << setfill('*') << setw(3*colWidth) << "*" << endl;
    cout << setfill(' ') << fixed;
    cout << setw(colWidth) <<"Value"<< setw(colWidth) <<" Population" << setw(colWidth) << "Fitness Score" <<endl;
    cout << setfill('*') << setw(3*colWidth) << "*" << endl;
    cout << setfill(' ') << fixed;
    for(i=0;i<10;i++)
    {
        fit = cal_fitness(pop[i]);
        cout << setw(colWidth) << pop[i] << setw(colWidth) << to_bin(pop[i])<< setw(colWidth) <<fit <<  endl;
        if(fit>max2)
        {
            if(fit>max1)
            {
                max2 = max1;
                index2 = index1;
                max1 = fit;
                index1 = i;
                continue;
            }
            max2 = fit;
            index2 = i;
        }
    }
    cout<<"\n\tThe two fittest are : "<<pop[index1]<<" and "<<pop[index2]<<"\n\n\n";

        gen = 2;
    crossover(pop[index1],pop[index1],gen);

    cout<<"\t\t\t Generation :  "<<pop[10]<<"\n";
    cout << setfill('*') << setw(3*colWidth) << "*" << endl;
    cout << setfill(' ') << fixed;
    cout << setw(colWidth) <<"Value"<< setw(colWidth) <<" Population" << setw(colWidth) << "Fitness Score" <<endl;
    cout << setfill('*') << setw(3*colWidth) << "*" << endl;
    cout << setfill(' ') << fixed;
    for(i=0;i<10;i++)
    {
        fit = cal_fitness(pop[i]);
        cout << setw(colWidth) << pop[i] << setw(colWidth) << to_bin(pop[i])<< setw(colWidth) <<fit <<  endl;
        if(fit>max2)
        {
            if(fit>max1)
            {
                max2 = max1;
                index2 = index1;
                max1 = fit;
                index1 = i;
                continue;
            }
            max2 = fit;
            index2 = i;
        }
    }
    cout<<"\n\tThe two fittest are : "<<pop[index1]<<" and "<<pop[index2]<<"\n\n\n";

            gen = 3;
    crossover(pop[index1],pop[index1],gen);

    cout<<"\t\t\t Generation :  "<<pop[10]<<"\n";
    cout << setfill('*') << setw(3*colWidth) << "*" << endl;
    cout << setfill(' ') << fixed;
    cout << setw(colWidth) <<"Value"<< setw(colWidth) <<" Population" << setw(colWidth) << "Fitness Score" <<endl;
    cout << setfill('*') << setw(3*colWidth) << "*" << endl;
    cout << setfill(' ') << fixed;
    for(i=0;i<10;i++)
    {
        fit = cal_fitness(pop[i]);
        cout << setw(colWidth) << pop[i] << setw(colWidth) << to_bin(pop[i])<< setw(colWidth) <<fit <<  endl;
        if(fit>max2)
        {
            if(fit>max1)
            {
                max2 = max1;
                index2 = index1;
                max1 = fit;
                index1 = i;
                continue;
            }
            max2 = fit;
            index2 = i;
        }
    }
    cout<<"\n\tThe two fittest are : "<<pop[index1]<<" and "<<pop[index2]<<"\n\n\n";







    return 0;
}
