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

void pros4(set<int> & temp,int n,int bsize, map<set<int>,int> & check, vector<set<int> > & beauty)
{
   vector<int> tem;
   for(int x : temp) { tem.push_back(x); }
   int tro = 0;
   while(tro<tem.size())
   {
       int m = tem.size();
       for (int i = tro;i<m;i++)
         { 
             for(int j = 0;j<=i;j++)
            {
                  int x = (tem[i]*tem[j])%n;
                  if(x==1) continue;
                  if(temp.count(x)==0)
                  {
                      check[temp] = pink;
                      temp.insert(x);
                      tem.push_back(x);
                  }
              if(check[temp]!=0) break;
            }
            if(check[temp]!=0) break;
          }
        tro = m;
        if(check[temp]!=0) break;
   }
   if(temp.size() == bsize) check[temp] = Green;
   else if(check[temp]==0)
   {
       check[temp] = green;
       beauty.push_back(temp);
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
    
     clock_t start, end;   // Khai báo biến thời gian
        double time_use;      // Thời gian sử dụng
        start = clock();  
    
    for(int n = 3; n<=110;n++)
    {
        int s = clock();
        
         vector<int> B;
        //B1: tim cac so nguyen to cn voi a, goi la day B
        B = pros1(n);
        //print(B);
        //cout <<B.size();
       
        //B3: xem color cua cac tap con 1 phan tu trong B
        map<set<int>, int> check;
        int bsize =B.size();
        vector<set<int> > beauty;
      
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
     /*   cout<<"so tap dep la "<< beauty.size() + 2<<endl;
        cout <<1 << endl;
         for(set<int> u : beauty)
        {
           cout<<"1 "; print(u);cout<<endl;
        }
        cout << "1 ";print(B);
        */
        int e = clock();  // lấy thời gian sau khi thực hiện 
        time_use = (double)(e - s) / CLOCKS_PER_SEC;    //Tính thời gian sử dụng
        cout<<"Thoi gian chay cho " << n << " la "<<time_use << endl;
    }
    end = clock();
    cout << "Tong thoi gian la ";
    cout << (double)(end - start)/CLOCKS_PER_SEC << endl;
   return 0;
}




