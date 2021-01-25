// Given two strings
#include<iostream>
using namespace std;

int main()
{
    string txt,pat;
    getline(cin,txt);
    getline(cin,pat);
    int ctxt[200]={0},cpat[200]={0},i,j,lent,lenp,temp,flag=0;
    lent = txt.length();
    lenp = pat.length();
    for(i=0;i<lenp;i++)
    {
        temp = (int)pat[i];
        cpat[temp]++;
    }
    for(i=0; i<lent-lenp+1; i++)
    {
        flag = 0;
        for(j = 0; j < lenp; j++)
        {
            temp = (int)txt[i+j];
            ctxt[temp]++;
        }
        for(j = 0; j < lenp; j++)
        {
            temp = (int)pat[j];

            if(ctxt[temp]==cpat[temp])
                flag=1;
            else
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
            cout<<i<<"\n";
        for(j=0;j<200;j++)
            ctxt[j]=0;

    }

    return 0;
}
//
