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
    cout<<"\t\t\t\t\tRobust Test\n";
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
    int input1[] = {min1-1,min1,min1+1,nom1,max1-1,max1,max1+1};
    int input2[] = {min2-1,min2,min2+1,nom2,max2-1,max2,max2+1};

    int colWidth=15;
    //table header
    cout << setfill('*') << setw(6*colWidth) << "*" << endl;
    cout << setfill(' ') << fixed;
    cout << setw(colWidth) << "Test Case ID" << setw(colWidth) << "Input 1" << setw(colWidth) << "Input 2" << setw(colWidth) << "Exp. Output" << setw(colWidth) << "Obv. Output" << setw(colWidth) << "Result" << endl;
    cout << setfill('*') << setw(6*colWidth) << "*" << endl;
    cout << setfill(' ') << fixed;
    int j=1,i,temp;
    string res;
    for(i=0;i<7;i++)
    {
        temp = (exp_op(input1[i],nom2)==obv_op(input1[i],nom2));
        if(temp)
            res="PASS";
        else
            res="FAIL";
        cout << setw(colWidth) <<j++<< setw(colWidth) <<input1[i]<< setw(colWidth) <<nom2<< setw(colWidth) << exp_op(input1[i],nom2) << setw(colWidth) << obv_op(input1[i],nom2) << setw(colWidth) <<res<< endl;
        temp = (exp_op(nom1,input2[i])==obv_op(nom1,input2[i]));
        if(temp)
            res="PASS";
        else
            res="FAIL";
        if(i!=3)
            cout << setw(colWidth) <<j++<< setw(colWidth) <<nom1<< setw(colWidth) <<input2[i]<< setw(colWidth) << exp_op(nom1,input2[i]) << setw(colWidth) << obv_op(nom1,input2[i]) << setw(colWidth) <<res<< endl;
    }
    cout<<"\n\n";
    return 0;
}

