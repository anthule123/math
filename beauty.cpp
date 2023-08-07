/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

#define green 3
#define pink 1
#define Green 4
vector<int> pros1(int n)
{
    vector<int> a;
    for (int j = 2;j<n;j++)
    {
        if (__gcd(j,n)==1) 
           a.push_back(j);
    }
    return a;
}
template <class tap>

void print(tap& a)
{
    for (int u : a)
      {  cout << u << " "; }
    cout << endl;
}
vector< vector<int> > pros2(vector<int>&b, int & n)
{
    int bsize = b.size();
    vector< vector<int> > bang;
 
    bang.assign(bsize, vector<int> (bsize,0));
    //for (vector<int> U: bang) {print(U);};
    for (int i = 0; i<bsize;i++)
      for( int j = 0;j<bsize;j++)
      {
          bang[i][j] = (b[i]*b[j])%n;
      }
    return bang;  
}
int pros3(set<int>&a, int n,int bsize, map< set<int>,int>& check)
{
    int rest = 0;
    set<int> them;
    for (int u: a)
      for(int v: a)
      {
          int   x = (u*v)%n;
          if(x==1) continue;
          if(a.count(x)==0)
          {
              rest = x;
              check[a] = pink;
              them.insert(x);
          }
      }
    a.insert(them.begin(),them.end());
    return rest;
}
void pros4(set<int> & temp,int n,int bsize, map<set<int>,int> & check, vector<set<int> > & beauty)
{
    while(check[temp]!=Green && check[temp]!=green)
    {
        if(pros3(temp,n,bsize,check) ==0)
        {
          if(temp.size() == bsize) { check[temp]=Green;}
          else if (temp.size() <bsize) {check[temp]=green;beauty.push_back(temp);}
        }
    }
}
void pros5(int n, int bsize, map<set<int>,int> &check, vector<set<int> > & beauty)
{
    int tro = 1;
    while(tro<beauty.size())
    {
        int m = beauty.size();
        for(int i = tro;i<m;i++)
          for(int j = 0; j<i;j ++)
          {
              set<int> te = beauty[i];
              te.insert(beauty[j].begin(),beauty[j].end());
              if(check[te]==0) 
              {
                  pros4(te,n,bsize,check,beauty);
              }
          }
        tro = m;
    }
}
int main()
{
    freopen("neu","w",stdout);
    printf("Hello World\n");
    
    vector<int> B;
    int n = 105;
    //B1: tim cac so nguyen to cn voi a, goi la day B
    B = pros1(n);
    //print(B);
    //cout <<B.size();
   // B2: co bang tich cac cap so trong B
    //vector<vector<int> > bang = pros2(B,n);
    //for (vector<int> U: bang) {print(U);};
    //B3: xem color cua cac tap con 1 phan tu trong B
    map<set<int>, int> check;
    int bsize =B.size();
    vector<set<int> > beauty;
   /* for (int u: B)
    {
        set<int> s = {u};
        print(s);
        int l = pros3(s,n,bsize,check);
        cout << "sau khi chinh: ";
        print (s);
    }
    */
    for (int u: B)
    {
        set<int> s = {u};
     //   print(s);
        pros4(s,n,bsize,check,beauty);
     //   cout << "sau khi Chinh: ";
       //  print (s);
    }
    /*
    for(set<int> u : beauty)
    {
        print(u);
    }*/
    pros5(n,bsize,check,beauty);
    cout<<"so tap dep la "<< beauty.size() + 2<<endl;
    cout <<1 << endl;
     for(set<int> u : beauty)
    {
       cout<<"1 "; print(u);cout<<endl;
    }
    cout << "1 ";print(B);
    return 0;
}
