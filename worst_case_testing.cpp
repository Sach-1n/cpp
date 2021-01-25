#include<iostream>
#include<iomanip>

using namespace std;

int exp_op(int input1, int input2)
{
    if(input1>input2)
        return input1;
    else
        return input2;
}

int obv_op(int input1, int input2)
{
    return input1;
}

int main()
{
    cout<<"\n\t\t\t\t\tWorst-Case Test\n";
    cout<<"\t\t\t\t\t(Output = Highest Score)\n\n";
    // Let us consider two players with their scores stored in to different arrays
    int score1[10] = {6,57,32,100,159,70,3,89,90,48};
    int scroe2[10] = {61,85,34,29,219,88,51,62,0,82};
    int max1=159;
    int max2=219;
    int min1=3;
    int min2=0;
    int nom1 = (max1+min1)/2;
    int nom2 = (max2+min2)/2;
    int input1[] = {min1,min1+1,nom1,max1-1,max1};
    int input2[] = {min2,min2+1,nom2,max2-1,max2};

    int colWidth=15;
    //table header
    cout << setfill('*') << setw(6*colWidth) << "*" << endl;
    cout << setfill(' ') << fixed;
    cout << setw(colWidth) << "Test Case ID" << setw(colWidth) << "Input 1" << setw(colWidth) << "Input 2" << setw(colWidth) << "Exp. Output" << setw(colWidth) << "Obv. Output" << setw(colWidth) << "Result" << endl;
    cout << setfill('*') << setw(6*colWidth) << "*" << endl;
    cout << setfill(' ') << fixed;
    int j=1,i,temp,k;
    string res;
    for(i=0;i<5;i++)
    for(k=0;k<5;k++)
    {
        temp = (exp_op(input1[i],input2[k])==obv_op(input1[i],input2[k]));
        if(temp)
            res="PASS";
        else
            res="FAIL";
        cout << setw(colWidth) <<j++<< setw(colWidth) <<input1[i]<< setw(colWidth) <<input2[k]<< setw(colWidth) << exp_op(input1[i],input2[k]) << setw(colWidth) << obv_op(input1[i],input2[k]) << setw(colWidth) <<res<< endl;


    }
    cout<<"\n\n";
    return 0;
}

