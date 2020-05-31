#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

int ne[20];
void GetNext(char *a)
{
    int len = strlen(a);
    int i = 0, j = -1;
    ne[0] = -1;
    while(i < len)
    {
        if(j == -1 || a[i] == a[j])
        {
            ne[++i] = ++j;
        }
        else j = ne[j];
    }
}

int KMP(char *a, char *b)
{
    int lena = strlen(a);
    int lenb = strlen(b);
    int i = 0, j = 0;
    while (i < lena && j < lenb)
    {
        if(j == -1 || a[i] == b[j])
        {
            j++;
            i++;
        }
        else
            j = ne[j];
    }
    if(j == lenb)
        return i-j+1;
    else
        return -1;
}

int main()
{
    char s[100]="0050dac6f2d600b0d04dcbaa08004500015731054000800600000a0a0231d850";
    char t[100]="dac6f2d6";
    //scanf("%s", &s);
    //scanf("%s", &t);
    GetNext(t);
    int k=KMP(s,t);
    if(k==-1)
        cout<<"不匹配"<<endl;
    else cout <<"匹配处："<<k<< endl;

    return 0;
}
